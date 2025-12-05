#include "Magasin.h"

Magasin::Magasin() :
	products_(std::vector<Product> {}), clients_(std::vector<Client> {}), orders_(std::vector<Order> {})
{
}
