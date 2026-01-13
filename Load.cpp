#include "Load.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

const std::vector<Client>& LoadClient()
{
	std::vector<Client> clients;
	std::vector<Product> panier;

	std::ifstream ClientsFile("Clients.csv");
	std::ifstream ClientPanierFile("ClientPanier.csv");

	std::string ligne, ligne2;
	while (std::getline(ClientsFile, ligne)) {
		std::stringstream ss(ligne);
		std::string id, name, surname;

		std::getline(ss, id, ';');
		std::getline(ss, name, ';');
		std::getline(ss, surname, ';');

		while (std::getline(ClientPanierFile, ligne2)) {
			std::stringstream ss2(ligne);
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

		clients.push_back(Client(stoi(id), name, surname, panier));
	}

	
		
	return clients;
}

const std::vector<Product>& LoadProduct()
{
	return std::vector<Product>();
}

const std::vector<Commande>& LoadCommande()
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
