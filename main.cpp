#include <iostream>
#include "Magasin.h"


int main() {

	srand((unsigned int)time(0));


	Magasin magasin = Magasin();

	Product produit1 = Product("PS4", "Console de jeu de la marque Sony", 5, 124.4);
	Product produit2 = Product("PS5", "Console de jeu de la marque Sony", 2, 1024.4);

	
	magasin.addNewProduct(produit1);
	magasin.addNewProduct(produit2);



	std::cout << magasin.products();

	std::cout << produit1.id() << std::endl;
	std::cout << produit2.id() << std::endl;

	return 0;
}