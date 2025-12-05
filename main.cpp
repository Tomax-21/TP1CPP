#include <iostream>
#include "Magasin.h"


int main() {
	Magasin magasin();

	Product produit1("PS4", "Console de jeu de la marque Sony", 5, 124.4);

	std::cout << produit1 << std::endl;

	return 0;
}