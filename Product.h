#pragma once

#include <string>
#include <iostream>
#include <random>
class Product
{
private:
	unsigned int id_;
	std::string title_;
	std::string description_;
	int quantity_;
	float unit_price_;


public:
	Product(std::string const& title, std::string const& description, int const& quantity, float const& unit_price);

	long int id() const;
	std::string title() const;
	std::string description() const;
	int quantity() const;
	float unit_price() const;

	void setQuantity(int const& quantity);
	
	friend std::ostream& operator<<(std::ostream& os, const Product& product);


	bool operator==(Product& product)const;
};

unsigned int generate_random_product_id();
