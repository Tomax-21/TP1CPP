#include "Load.h"

const std::vector<Client>& LoadClient()
{
	return std::vector<Client>();
}

const std::vector<Product>& LoadProduct()
{
	return std::vector<Product>();
}

const std::vector<Commande>& LoadCommande()
{
	return std::vector<Commande>();
}

Magasin LoadAll()
{
	std::vector<Client> clients = LoadClient();
	std::vector<Product> products = LoadProduct();
	std::vector<Commande> commandes = LoadCommande();

	return Magasin(clients, products, commandes);
}
