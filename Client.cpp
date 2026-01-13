#include "Client.h"

std::ostream& operator<<(std::ostream& os, const Client& client)
{
	os << "Id : " << client.id_ << std::endl;
	os << "Nom : " << client.nom_ << " Prenom : " << client.prenom_ << std::endl;
	for (Product produit : client.panier_) {
		os << produit << std::endl;

	}
	os << std::endl;

	return os;
}

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

void Client::setProductQuantityByName(std::string const& product_name, int const& quantity)
{
	for (Product& product : panier_) {
		if (product.title() == product_name) {
			product.setQuantity(quantity);
		}
	}
}


void Client::removeProductFromPanier(std::string product_name)
{
	for (auto it = panier_.begin(); it != panier_.end(); ++it) {
		if (it->title() == product_name) {
			panier_.erase(it);
			return;
		}
	}
}

std::string Client::getName() const
{
	return nom_;
}

int Client::getId() const
{
	return id_;
}

std::vector<Product> Client::panier() const
{
	return panier_;
}

void Client::setName(std::string name)
{
	nom_ = name;
}

void Client::setPrenom(std::string prenom)
{
	prenom_ = prenom;
}

std::string Client::getSurname() const
{
	return prenom_;
}
