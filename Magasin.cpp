#include "Magasin.h"

Magasin::Magasin() :
	products_(std::vector<Product> {}), clients_(std::vector<Client> {}), orders_(std::vector<Order> {})
{
}

void Magasin::addNewProduct(Product const& product)
{
	products_.push_back(product);
}
