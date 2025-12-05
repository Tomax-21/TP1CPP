#pragma once

#include <string>
#include <iostream>

class Product
{
private:
	std::string id_;
	std::string title_;
	std::string description_;
	int quantity_;
	float unit_price_;


public:
	Product(std::string const& title, std::string const& description, int const& quantity, float const& unit_price);

	std::string title() const;
	std::string description() const;
	int quantity() const;
	float unit_price() const;

	void setQuantity(int const& quantity);
	
	friend std::ostream& operator<<(std::ostream& os, const Product& product);
};

