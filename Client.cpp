#include "Client.h"

unsigned int generate_random_client_id()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 1000000);
	return dist(gen);
}

Client::Client(std::string const& prenom, std::string const& nom):
	id_(generate_random_client_id()), prenom_(prenom), nom_(nom)
{
}

void Client::addProductToPanier(Product const& produit)
{
	panier_.push_back(produit);
}

void Client::emptyPanier()
{
	panier_.clear();
}
