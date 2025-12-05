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

	void addNewProduct(Product const& product);

};

std::ostream& operator<<(std::ostream& os, std::vector<Product> const& produit);
