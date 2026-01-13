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
		std::cout << "2 : Gerer les clients" << std::endl;
		std::cout << "3 : Gerer les commandes" << std::endl;


	
	do {
		std::getline(std::cin, choix);
		if (choix != "1" && choix != "2" && choix != "3" && choix != "exit") {
			std::cout << "Choix incorrect, votre choix doit se situer etre un chiffre entre 1 et 3" << std::endl;
		}
	} while (choix != "1" && choix != "2" && choix != "3");

	if (choix == "1") {
		menu1(magasin);
	}
	if (choix == "2") {
		menu2(magasin);
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
		std::cout << "5 : Modifier la quantite d'un produit" << std::endl;
		std::cout << "6 : Afficher toutes les commandes" << std::endl;

	
		do {
			std::getline(std::cin, choix);
			if (choix != "1" && choix != "2" && choix != "3" && choix != "4" && choix != "5" && choix != "6" && choix != "exit") {
				std::cout << "Choix incorrect, votre choix doit se situer etre un chiffre entre 1 et 6" << std::endl;
			}
		} while (choix != "1" && choix != "2" && choix != "3" && choix != "4" && choix != "5" && choix != "6" && choix != "exit");

		if (choix == "1") {
			show_all_clients_hud(magasin);
		}
		if (choix == "2") {
			create_client_hud(magasin);
		}
		if (choix == "3") {
			show_all_products_hud(magasin);
		}
		if (choix == "4") {
			add_product_hud(magasin);
		}
		if (choix == "5") {
			modify_product_quantity_hud(magasin);
		}
		if (choix == "6") {
			show_all_commandes_hud(magasin);
		}
	} while (choix != "exit");



}

void create_client_hud(Magasin& magasin) {
	std::string prenom;
	std::string nom;
	std::cout << "Entrez le prenom du client : ";
	std::getline(std::cin, prenom);

	std::cout << "Entrez le nom du client : ";
	std::getline(std::cin, nom);

	Client client = Client(prenom, nom);

	magasin.addNewClient(client);
}
void add_product_hud(Magasin& magasin) {
	//std::string const& title, std::string const& description, int const& quantity, float const& unit_price)
	std::string name;
	std::string desc;

	std::string quantity;
	std::string price;

	std::cout << "Entrez le nom du produit : ";
	std::getline(std::cin, name);

	std::cout << "Entrez la description du produit : ";
	std::getline(std::cin, desc);

	std::cout << "Entrez la quantite du produit : ";
	std::getline(std::cin, quantity);

	std::cout << "Entrez le prix du produit : ";
	std::getline(std::cin, price);

	Product produit = Product(name, desc, stoi(quantity), stof(price));

	magasin.addNewProduct(produit);
}


void menu2(Magasin& magasin) {
	std::cout << "Que souhaitez vous faire ?" << std::endl;

	std::string choix;
	do {
		std::cout << "1 : Afficher tous les clients ?" << std::endl;
		std::cout << "2 : Afficher un client ?" << std::endl;
		std::cout << "3 : Ajouter un client ?" << std::endl;
		std::cout << "4 : Modifier un client ?" << std::endl;
		std::cout << "5 : Supprimer un client ?" << std::endl;
		std::cout << "6 : Ajouter un produit au panier du client ?" << std::endl;
		std::cout << "7 : Supprimer un produit au panier du client ? " << std::endl;
		std::cout << "8 : Afficher le panier d'un client" << std::endl;


		do {
			std::getline(std::cin, choix);
			if (choix != "1" && choix != "2" && choix != "3" && choix != "4" && choix != "5" && choix != "6" && choix != "7" && choix != "8" && choix != "exit") {
				std::cout << "Choix incorrect, votre choix doit etre un chiffre entre 1 et 8" << std::endl;
			}
		} while (choix != "1" && choix != "2" && choix != "3" && choix != "4" && choix != "5" && choix != "6" && choix != "7" && choix != "8" && choix != "exit");

		if (choix == "1") {
			show_all_clients_hud(magasin);
		}
		if (choix == "2") {
			research_client_hud(magasin);
		} if (choix == "3") {
			create_client_hud(magasin);
		} if (choix == "4") {
			modify_client_hud(magasin);
		}

	} while (choix != "exit");
}

void show_all_products_hud(Magasin& magasin) {
	std::cout << magasin.products() << std::endl;
}

void show_all_commandes_hud(Magasin& magasin) {
	std::cout << magasin.getCommandes() << std::endl;
}

void show_all_clients_hud(Magasin& magasin) {
	std::cout << magasin.getClients() << std::endl;
}




void research_client_hud(Magasin& magasin) {
	// afficher un client precis
	std::string val;
	std::string choix;

	do {
		std::cout << "Rechercher par (1) id ou par (2) nom";
		std::getline(std::cin, choix);
	} while (choix != "1" && choix != "2");
	
	try {
		if (choix == "1") {
			std::cout << "Quelle est l'id du client ? : ";
			std::getline(std::cin, val);
			std::cout << magasin.getClientById(stoi(val)) << std::endl;
		}
		else if (choix == "2") {
			std::cout << "Quelle est le nom du client ? : ";
			std::getline(std::cin, val);
			std::cout << magasin.getClientByName(val) << std::endl;
		}
	}
	catch (const std::runtime_error& e) {
		std::cout << "Client Introvable";
	} 
}



void modify_product_quantity_hud(Magasin& magasin) {
	std::string nom;
	std::string quantity;

	std::cout << "Quel est le nom du produit ? : ";
	
	std::getline(std::cin, nom);

	std::cout << "Quelle est la nouvelle quantite ? : ";

	std::getline(std::cin, quantity);

	try {
		updateProductQuantityByName(magasin, nom, stoi(quantity));
	}
	catch (std::runtime_error& e) {
		std::cout << "Produit non trouve : " << nom << std::endl;
	}
	
}

void show_product(Magasin& magasin)
{
	std::string nom;
	std::cout << "Quelle est le nom du produit ?";

	try {
		std::cout << magasin.getProductByName(nom)<< std::endl;
	}
	catch (std::runtime_error& e) {
		std::cout << "produit non trouve : " << nom << std::endl;
	}
	
}

void modify_client_hud(Magasin& magasin)
{
	std::string current_name;
	std::string new_name;
	std::string new_surname;


	std::cout << "Modifier un client" << std::endl;
	std::cout << "Quelle est son nom ? : ";
	std::getline(std::cin, current_name);

	try {
		Client client = magasin.getClientByName(current_name);

		std::cout << "Ancien nom : " << client.getName() << " Nouveau nom : ";
		std::getline(std::cin, new_name);
		std::cout << "Ancien prenom : " << client.getSurname() << " Nouveau prenom : ";
		std::getline(std::cin, new_surname);

		update_clients(magasin, client, new_name, new_surname);
	}
	catch (std::runtime_error& e) {
		std::cout << "Client introuvable";
	}

}
