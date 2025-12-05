#include "Product.h"

Product::Product(std::string const& title, std::string const& description, int const& quantity, float const& unit_price):
	title_(title), description_(description), quantity_(quantity), unit_price_(unit_price)
{
	if (quantity < 0) {
		throw std::invalid_argument("La quantité doit etre une valeur positive ou nulle");
	}
	if (unit_price < 0) {
		throw std::invalid_argument("Le prix unitaire doit etre une valeur positive ou nulle");
	}
}