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

	void addNewProduct(Product& product);


	Product& getProductByName(std::string const& product_name);

	

};


void updateProductQuantityByName(Magasin& magasin, std::string const& product_name, int const& quantity);

std::ostream& operator<<(std::ostream& os, std::vector<Product> const& produit);
