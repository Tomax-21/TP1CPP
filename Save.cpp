#include "Save.h"

#include <fstream>
#include <iostream>


void SaveClient(std::vector<Client> clients)
{
	std::ofstream ClientsFile("Clients.csv");
	std::ofstream ClientPanierFile("ClientPanier.csv");


	for (Client& client : clients) {
		ClientsFile << client.getId() << ";" << client.getName() << ";" << client.getSurname() << std::endl;
		for (Product& product : client.panier()) {
			ClientPanierFile << client.getId() << ";" << product.id() << ";" << product.title() << ";" << product.description() << ";" << product.quantity() << ";" << product.unit_price() << std::endl;
		}
	}

	ClientsFile.close();
	ClientPanierFile.close();

}

void SaveProduct(std::vector<Product> products)
{
	std::ofstream ProductsFile("Products.csv");

	for (Product& product : products) {
		ProductsFile << product.id() << ";" << product.title() << ";" << product.description() << ";" << product.quantity() << ";" << product.unit_price() << std::endl;
	}

	ProductsFile.close();
}

void SaveCommande(std::vector<Commande> commandes)
{
	std::ofstream CommandesFile("Commandes.csv");
	std::ofstream CommandeProductsFile("ProductsCommande.csv");

	for (Commande& commande : commandes) {
		CommandesFile << commande.id() << ";" << commande.client().getId() << ";" << commande.string_statut() << std::endl;
		for (Product& product : commande.produits()) {
			CommandeProductsFile << commande.id() << ";" << product.id() << ";" << product.title() << ";" << product.description() << ";" << product.quantity() << ";" << product.unit_price() << std::endl;
		}
	}

	CommandesFile.close();
	CommandeProductsFile.close();
}


void SaveAll(Magasin& magasin)
{
	SaveClient(magasin.getClients());
	SaveProduct(magasin.products());
	SaveCommande(magasin.getCommandes());

}
