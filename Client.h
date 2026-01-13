#pragma once
#include <random>
#include <string>
#include <vector>

#include "Product.h"
#include <iostream>

class Client
{
private:
	int id_;
	std::string prenom_;
	std::string nom_;
	std::vector<Product> panier_;

public:
	Client(std::string const& prenom, std::string const& nom);
	Client(const int& id, std::string const& prenom, std::string const& nom, const std::vector<Product>& panier);

	void addProductToPanier(Product const& produit);

	void emptyPanier();

	void setProductQuantityByName(std::string const& product_name, int const& quantity);

	void removeProductFromPanier(std::string product_name);

	friend std::ostream&operator << (std::ostream & os, const Client & client);

	std::string getName() const;
	std::string getSurname() const;
	int getId() const;
	std::vector<Product> panier() const;

	void setName(std::string name);
	void setPrenom(std::string prenom);



};

unsigned int generate_random_client_id();
