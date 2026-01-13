#pragma once
#include "Client.h"
#include "Product.h"
#include "CommandeStatut.h"
#include <vector>
#include <iostream>

class Commande
{
private :
	unsigned int id_;
	Client client_;
	std::vector<Product> produits_;
	CommandeStatut statut_;

public:
	Commande(const Client& client, const CommandeStatut statut);
	Commande(const Client& client);
	friend std::ostream& operator<<(std::ostream& os, const Commande& commande);

	void setStatut(const CommandeStatut& statut);

	void addProduct(const Product& product);
	Client client();
	unsigned int id();
	CommandeStatut statut();
	std::vector<Product> produits();

	std::string string_statut();
};
