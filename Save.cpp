#include "Save.h"

#include <fstream>
#include <iostream>


void SaveClient(std::vector<Client> clients)
{
	std::ofstream ClientFile("Client.csv");

	for (Client& client : clients) {
		ClientFile << client.getId() << ";" << client.getName() << ";" << client.getSurname() << std::endl;
	}
}

void SaveAll(Magasin& magasin)
{
	SaveClient(magasin.getClients());
	SaveProduct(magasin.products());
	SaveCommande(magasin.getCommandes());

}
