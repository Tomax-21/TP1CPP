#pragma once
#include "Magasin.h"



std::vector<Client> LoadClient();
std::vector<Product> LoadProduct();
std::vector<Commande> LoadCommande();

Magasin LoadAll();
