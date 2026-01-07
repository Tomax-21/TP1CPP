#pragma once
#include "Client.h"
#include "Product.h"
#include "CommandeStatut.h"
#include <vector>
#include <iostream>

class Commande
{
private :
	Client client_;
	std::vector<Product> produits_;
	CommandeStatut statut_;

public:
	Commande(const Client& client, const CommandeStatut statut);
	friend std::ostream& operator<<(std::ostream& os, const Commande& commande);
};
