#pragma once
#include <random>
#include <string>
#include <vector>

#include "Product.h"
class Client
{
private:
	int id_;
	std::string prenom_;
	std::string nom_;
	std::vector<Product> panier_;

public:
	Client(std::string const& prenom, std::string const& nom);

	void addProductToPanier(Product const& produit);
};

unsigned int generate_random_client_id();
