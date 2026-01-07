#include "Magasin.h"

Magasin::Magasin() :
	products_(std::vector<Product> {}), clients_(std::vector<Client> {}), orders_(std::vector<Order> {})
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




Product& Magasin::getProductByName(std::string const& product_name)
{
	for (Product& product : products_) {
		if (product.title() == product_name) {
			return product;
		}
	}
	throw std::runtime_error("Produit non trouvé : " + product_name);
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










void show_clients(Magasin& magasin)
{

	for (Client& client : magasin.getClients()) {
		std::cout << client << std::endl;
	}
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











std::ostream& operator<<(std::ostream& os, std::vector<Product> const& products)
{
	os << "Affichage de la liste des produits du magasin : " << std::endl;

	for (Product product : products) {
		os << std::endl << product  << std::endl;
	}

	os << "############" << std::endl;

	return os;
}
