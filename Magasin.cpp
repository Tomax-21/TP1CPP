#include "Magasin.h"

Magasin::Magasin() :
	products_(std::vector<Product> {}), clients_(std::vector<Client> {}), orders_(std::vector<Commande> {})
{
}

Magasin::Magasin(const std::vector<Client>& clients, const std::vector<Product>& products, const std::vector<Commande>& commandes):
	clients_(clients), products_(products), orders_(commandes)
{
}

std::vector<Product> Magasin::products() const
{
	return products_;
}

void Magasin::addNewProduct(const Product& product)
{
	products_.push_back(product);
}

void Magasin::addNewClient(const Client& client)
{
	clients_.push_back(client);
}

void Magasin::removeClient(const Client& client)
{
	for (auto it = clients_.begin(); it != clients_.end(); ++it) {
		if (it->getId() == client.getId()) {
			clients_.erase(it);
			return;
		}
	}
}

std::vector<Client> Magasin::getClients()
{
	return clients_;
}

Client& Magasin::getClientByName(std::string const& client_name)
{
	for (Client& client : clients_) {
		if (client.getName() == client_name) {
			return client;
		}
	}
	throw std::runtime_error("Client non trouvé" + client_name);
}

Client& Magasin::getClientById(int const& client_id)
{
	for (Client& client : clients_) {
		if(client.getId() == client_id) {
			return client;
		}
	}
	throw std::runtime_error("Client non trouvé" + client_id);
}

void Magasin::addNewOrder(const Commande& commande)
{
	orders_.push_back(commande);
}

std::vector<Commande> Magasin::getCommandes()
{
	return orders_;
}

Commande& Magasin::getCommandeById(const unsigned int commande_id)
{
	for (Commande& commande : orders_) {
		if (commande.id() == commande_id) {
			return commande;
		}
	}
	throw std::runtime_error("Commande non trouvé : " + commande_id);
}

void Magasin::valideOrderById(const unsigned int commande_id)
{
	Commande& commande = getCommandeById(commande_id);
	commande.setStatut(CommandeStatut::LIVRE);

}

void Magasin::changeOrderStatutById(const unsigned int commande_id, CommandeStatut statut)
{
	Commande& commande = getCommandeById(commande_id);
	commande.setStatut(statut);
}




Product& Magasin::getProductByName(std::string const& product_name)
{
	for (Product& product : products_) {
		if (product.title() == product_name) {
			return product;
		}
	}
	throw std::runtime_error("Produit non trouvé : " + product_name);
}








void add_product_to_commande(Magasin& magasin, const unsigned int commande_id, std::string const& product_name)
{
	Product& product = magasin.getProductByName(product_name);
	Commande& commande = magasin.getCommandeById(commande_id);

	commande.addProduct(product);

}

void add_product_to_client(Magasin& magasin, std::string const& product_name, const std::string& client_name)
{
	Client& client = magasin.getClientByName(client_name);
	Product& product = magasin.getProductByName(product_name);

	client.addProductToPanier(product);
}


void add_product_to_client(Magasin& magasin, std::string const& product_name, const int& client_id)
{
	Client& client = magasin.getClientById(client_id);
	Product& product = magasin.getProductByName(product_name);

	client.addProductToPanier(product);
}

void remove_product_to_client(Magasin& magasin, std::string const& product_name, const std::string& client_name)
{

	Client& client = magasin.getClientByName(client_name);
	client.removeProductFromPanier(product_name);
}

void remove_product_to_client(Magasin& magasin, std::string const& product_name, const int& client_id)
{
	Client& client = magasin.getClientById(client_id);
	client.removeProductFromPanier(product_name);
}

void change_product_quantity_to_client(Magasin& magasin, std::string const& product_name, const std::string& client_name, const int& quantity)
{
	Client& client = magasin.getClientByName(client_name);

	if (quantity == 0) {
		client.removeProductFromPanier(product_name);
	}
	else {
		client.setProductQuantityByName(product_name, quantity);
	}
}

void change_product_quantity_to_client(Magasin& magasin, std::string const& product_name, const int& client_id, const int& quantity)
{
	Client& client = magasin.getClientById(client_id);

	if (quantity == 0) {
		client.removeProductFromPanier(product_name);
	}
	else {
		client.setProductQuantityByName(product_name, quantity);
	}
}







void show_commande(Magasin& magasin) {
	for (Commande& commande : magasin.getCommandes()) {
		std::cout << commande << std::endl;
	}
}


void show_clients(Magasin& magasin)
{

	for (Client& client : magasin.getClients()) {
		std::cout << client << std::endl;
	}
}

void update_clients(Magasin& magasin, Client& client, std::string new_name, std::string new_surname)
{
	Client& client_magasin = magasin.getClientById(client.getId());
	client_magasin.setName(new_name);
	client_magasin.setPrenom(new_surname);
}

void updateProductQuantityByName(Magasin& magasin, std::string const& product_name, int const& quantity)
{
	// return true si le produit existe, false sinon
	try {
		Product& product = magasin.getProductByName(product_name);
		product.setQuantity(quantity);
	}
	catch (std::runtime_error& e) {
		throw std::runtime_error("Produit non trouvé : " + product_name);
	}
}











std::vector<Commande> getCommandeLivre(Magasin& magasin)
{
	std::vector<Commande> liste_commande;

	for (Commande& commande : magasin.getCommandes()) {
		if (commande.statut() == CommandeStatut::LIVRE) {
			liste_commande.push_back(commande);
		}
	}
	return liste_commande;
}

std::vector<Commande> getCommandeFromClient(Magasin& magasin, const Client& client)
{
	std::vector<Commande> liste_commande;

	for (Commande& commande : magasin.getCommandes()) {
		if (commande.client().getId() == client.getId()) {
			liste_commande.push_back(commande);
		}
	}
	return liste_commande;
}


std::ostream& operator<<(std::ostream& os, std::vector<Product> const& products)
{
	os << "Affichage de la liste des produits du magasin : " << std::endl;

	for (Product product : products) {
		os << std::endl << product  << std::endl;
	}

	os << "############" << std::endl;

	return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<Client> const& clients)
{
	os << "Affichage de la liste des clients du magasin : " << std::endl;

	for (Client client : clients) {
		os << std::endl << client << std::endl;
	}

	os << "############" << std::endl;

	return os;
}
std::ostream& operator<<(std::ostream& os, std::vector<Commande> const& commandes)
{
	os << "Affichage de la liste des commandes du magasin : " << std::endl;

	for (Commande commande : commandes) {
		os << std::endl << commande << std::endl;
	}

	os << "############" << std::endl;

	return os;
}
