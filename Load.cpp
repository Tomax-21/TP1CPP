#include "Load.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<Client> LoadClient()
{
	std::vector<Client> clients;

	std::ifstream ClientsFile("Clients.csv");
	std::ifstream ClientPanierFile("ClientPanier.csv");

	std::string ligne, ligne2;
	while (std::getline(ClientsFile, ligne)) {
		std::stringstream ss(ligne);
		std::string id, name, surname;

		std::getline(ss, id, ';');
		std::getline(ss, surname, ';');
		std::getline(ss, name, ';');

		std::vector<Product> panier;

		ClientPanierFile.clear(); // il faut recommencer la lecture du fichier
		ClientPanierFile.seekg(0);

		while (std::getline(ClientPanierFile, ligne2)) {

			std::stringstream ss2(ligne2);
			std::string idClient, idProduct, nameProduct, descProduct, quantity, unit_price;
			
			std::getline(ss2, idClient, ';');
			std::getline(ss2, idProduct, ';');
			std::getline(ss2, nameProduct, ';');
			std::getline(ss2, descProduct, ';');
			std::getline(ss2, quantity, ';');
			std::getline(ss2, unit_price, ';');
			
			if (idClient == id) {
				panier.push_back(Product(stoi(idProduct), nameProduct, descProduct, stoi(quantity), stof(unit_price)));
			}
		}
		std::cout << panier;
		clients.push_back(Client(stoi(id), surname, name, panier));
	}

	return clients;
}

std::vector<Product> LoadProduct()
{

	std::vector<Product> products;
	std::ifstream ProductsFile("Products.csv");

	std::string ligne, ligne2;
	while (std::getline(ProductsFile, ligne)) {
		std::stringstream ss(ligne);
		std::string id, name, desc, quant, price;

		std::getline(ss, id, ';');
		std::getline(ss, name, ';');
		std::getline(ss, desc, ';');
		std::getline(ss, quant, ';');
		std::getline(ss, price, ';');

		products.push_back(Product(stoi(id), name, desc, stoi(quant), stof(price)));
	}

	ProductsFile.close();

	return products;
}



std::vector<Commande> LoadCommande()
{
	return std::vector<Commande>();
}

Magasin LoadAll()
{
	std::vector<Client> clients = LoadClient();
	std::vector<Product> products = LoadProduct();
	std::vector<Commande> commandes = LoadCommande();

	return Magasin(clients, products, commandes);
}
