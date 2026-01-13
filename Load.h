#pragma once
#include "Magasin.h"



const std::vector<Client>& LoadClient();
const std::vector<Product>& LoadProduct();
const std::vector<Commande>& LoadCommande();

Magasin LoadAll();
