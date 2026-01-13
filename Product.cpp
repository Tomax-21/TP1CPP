#include "Product.h"



Product::Product(const unsigned int& id, std::string const& title, std::string const& description, int const& quantity, float const& unit_price):
id_(id), title_(title), description_(description), quantity_(quantity), unit_price_(unit_price)
{
}

Product::Product(std::string const& title, std::string const& description, int const& quantity, float const& unit_price):
	id_(generate_random_product_id()), title_(title), description_(description), quantity_(quantity), unit_price_(unit_price)
{
	if (quantity < 0) {
		throw std::invalid_argument("La quantité doit etre une valeur positive ou nulle");
	}
	if (unit_price < 0) {
		throw std::invalid_argument("Le prix unitaire doit etre une valeur positive ou nulle");
	}
}

void Product::setQuantity(int const& quantity)
{
	if (quantity < 0) {
		throw std::invalid_argument("La quantité doit etre positive ou nulle");
	}
	quantity_ = quantity;
}

bool Product::operator==(Product const& product) const
{
	return (id_ == product.id());
}

long int Product::id() const
{
	return id_;
}

std::string Product::title() const
{
	return title_;
}

std::string Product::description() const
{
	return description_;
}

int Product::quantity() const
{
	return quantity_;
}

float Product::unit_price() const
{
	return unit_price_;
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
	os << product.title_ << " : " << product.description_ << std::endl << "Quantity : " << product.quantity_ << std::endl << "Unit Price : " << product.unit_price_ << "€" << std::endl;
	return os;
}

#include <random>

unsigned int generate_random_product_id()
{
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> dist(1, 1000000);
	return dist(gen);
}
