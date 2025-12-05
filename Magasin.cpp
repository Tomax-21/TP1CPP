#include "Magasin.h"

Magasin::Magasin() :
	products_(std::vector<Product> {}), clients_(std::vector<Client> {}), orders_(std::vector<Order> {})
{
}

std::vector<Product> Magasin::products() const
{
	return products_;
}

void Magasin::addNewProduct(Product const& product)
{
	products_.push_back(product);
}

std::ostream& operator<<(std::ostream& os, std::vector<Product> const& produits)
{
	for (Product produit : produits) {
		os << produit << std::endl << "#######" << std::endl;
	}

	return os;
}
