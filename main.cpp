#include <iostream>
#include "Magasin.h"
#include "hud.h"
#include "Load.h"
int main() {

	srand((unsigned int)time(0));


	Magasin magasin = LoadAll();


	//Product produit1 = Product("PS4", "Console de jeu de la marque Sony", 5, 124.4);
	//Product produit2 = Product("PS5", "Console de jeu de la marque Sony", 2, 1024.4);

	
	//magasin.addNewProduct(produit1);
	//magasin.addNewProduct(produit2);

	//Client thomas = Client("Thomas", "MILLET");
	//thomas.addProductToPanier(produit1);
	//magasin.addNewClient(thomas);
	
	hud(magasin);


	//produit1.setQuantity(12);
	
	//std::cout << magasin.products() << std::endl;


	//Product& produit = magasin.getProductByName("PS4");

	//produit.setQuantity(1);
	//std::cout << magasin.products();


	//Client thomas = Client("Thomas", "MILLET");
	//thomas.addProductToPanier(produit1);
	//thomas.addProductToPanier(produit2);

	//std::cout << thomas;

	//thomas.removeProductFromPanier("PS4");

	//std::cout << thomas;


	//magasin.addNewClient(thomas);


	//Commande commande1 = Commande(thomas, CommandeStatut::NON_LIVRE);

	//magasin.addNewOrder(commande1);

	//magasin.valideOrderById(commande1.id());


	//int thomas_id = thomas.getId();
	//std::cout << magasin.getClientByName("MILLET") << std::endl;
	//std::cout << magasin.getClientById(thomas_id) << std::endl;
	
	//add_product_to_client(magasin, "PS4", "MILLET");

	//std::cout << magasin.getClientByName("MILLET") << std::endl;

	//change_product_quantity_to_client(magasin, "PS4", "MILLET", 12);

	//std::cout << magasin.getClientByName("MILLET") << std::endl;


	//remove_product_to_client(magasin, "PS4", "MILLET");


	//std::cout << magasin.getClientByName("MILLET") << std::endl;


	//show_clients(magasin);
	//thomas.removeProductFromPanier("PS4");
	//std::cout << "####" << std::endl;
	//show_clients(magasin);


	//try {	
	//	Product& produit = magasin.getProductByName("PS4");
	//	updateProductQuantityByName(magasin, "PS4", 1);
	//}
	//catch (const std::runtime_error& e) {
	//	std::cout << "Erreur : " << e.what() << std::endl;
	//}

	//std::cout << magasin.products() << std::endl;


	return 0;
}