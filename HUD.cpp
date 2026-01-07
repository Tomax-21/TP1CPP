#include <iostream>
#include <string>
#include "Magasin.h"
#include "HUD.h"

void hud(Magasin& magasin) {
	std::cout << "Bienvenue dans le systeme de management" << std::endl;

	std::cout << "que souhaitez vous faire ?" << std::endl;
	std::string choix;

	do {
		std::cout << "1 : Gerer le magasin" << std::endl;
		std::cout << "2 : Gerer les utilisateurs" << std::endl;
		std::cout << "3 : Gerer les commandes" << std::endl;


	
	do {
		std::cin >> choix;
		if (choix != "1" && choix != "2" && choix != "3" && choix != "exit") {
			std::cout << "Choix incorrect, votre choix doit se situer etre un chiffre entre 1 et 3" << std::endl;
		}
	} while (choix != "1" && choix != "2" && choix != "3");

	if (choix == "1") {
		menu1(magasin);
	}

	} while (choix != "exit");

}


void menu1(Magasin& magasin) {
	std::cout << "Que souhaitez vous faire ?" << std::endl;


	std::string choix;

	do {

	
		std::cout << "1 : Afficher tous les utilisateur" << std::endl;
		std::cout << "2 : Ajouter un utilisateur" << std::endl;
		std::cout << "3 : Afficher tous les produits" << std::endl;
		std::cout << "4 : Ajouter produits" << std::endl;
		std::cout << "5 : Afficher toutes les commandes" << std::endl;

	
		do {
			std::cin >> choix;
			if (choix != "1" && choix != "2" && choix != "3" && choix != "4" && choix != "5" && choix != "exit") {
				std::cout << "Choix incorrect, votre choix doit se situer etre un chiffre entre 1 et 5" << std::endl;
			}
		} while (choix != "1" && choix != "2" && choix != "3" && choix != "4" && choix != "5" && choix != "exit");

		if (choix == "1") {
			std::cout << magasin.getClients() << std::endl;
		}
		if (choix == "2") {
			menu1_2(magasin);
		}
		if (choix == "3") {
			std::cout << magasin.products() << std::endl;
		}
		if (choix == "4") {
			menu1_4(magasin);
		}
	} while (choix != "exit");



}

void menu1_2(Magasin& magasin) {
	std::string prenom;
	std::string nom;
	std::cout << "Entrez le prenom du client : ";
	std::cin >> prenom;

	std::cout << "Entrez le nom du client : ";
	std::cin >> nom;

	Client client = Client(prenom, nom);

	magasin.addNewClient(client);
}
void menu1_4(Magasin& magasin) {
	//std::string const& title, std::string const& description, int const& quantity, float const& unit_price)
	std::string name;
	std::string desc;
	int quantity;
	float price;
	std::cout << "Entrez le nom du produit : ";
	std::cin >> name;
	std::cout << "Entrez la description du produit : ";
	std::cin >> desc;
	std::cout << "Entrez la quantite du produit : ";
	std::cin >> quantity;
	std::cout << "Entrez le prix du produit : ";
	std::cin >> price;
	Product produit = Product(name, desc, quantity, price);

	magasin.addNewProduct(produit);
}