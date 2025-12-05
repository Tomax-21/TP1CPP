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

Product Magasin::getProductByName(std::string const& product_name) const
{
	for (Product product : products_) {
		if (product.title() == product_name) {
			return product;
		}
	}
	throw std::runtime_error("Produit non trouvé : " + product_name);
}

std::ostream& operator<<(std::ostream& os, std::vector<Product> const& produits)
{
	for (Product produit : produits) {
		os << produit << std::endl << "#######" << std::endl;
	}

	return os;
}
