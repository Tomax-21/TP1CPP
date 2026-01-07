#pragma once

#include <vector>
#include "Product.h"
#include "Client.h"
#include "Order.h"

class Magasin
{

private:
	std::vector<Product> products_;
	std::vector<Client> clients_;
	std::vector<Order> orders_;
public:
	Magasin();

	std::vector<Product> products() const;
	Product& getProductByName(std::string const& product_name);

	void addNewProduct(const Product& product);

	void addNewClient(const Client& client);

	std::vector<Client> getClients();

	Client& getClientByName(std::string const& client_name);
	Client& getClientById(int const& client_id);
};

void add_product_to_client(Magasin& magasin, std::string const& product_name, const std::string& client_name);
void add_product_to_client(Magasin& magasin, std::string const& product_name, const int& client_id);

void remove_product_to_client(Magasin& magasin, std::string const& product_name, const std::string& client_name);
void remove_product_to_client(Magasin& magasin, std::string const& product_name, const int& client_id);

void change_product_quantity_to_client(Magasin& magasin, std::string const& product_name, const std::string& client_name, const int& quantity);
void change_product_quantity_to_client(Magasin& magasin, std::string const& product_name, const int& client_id, const int& quantity);

void show_clients(Magasin& magasin);

void updateProductQuantityByName(Magasin& magasin, std::string const& product_name, int const& quantity);

std::ostream& operator<<(std::ostream& os, std::vector<Product> const& produit);
