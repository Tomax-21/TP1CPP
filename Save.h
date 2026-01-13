#pragma once
#include "Magasin.h"
#include <fstream>
#include <iostream>


void SaveClient(std::vector<Client> clients);
void SaveProduct(std::vector<Product> products);
void SaveCommande(std::vector<Commande> commandes);

void SaveAll(Magasin& magasin);

