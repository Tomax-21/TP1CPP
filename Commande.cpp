#include "Commande.h"

std::ostream& operator<<(std::ostream& os, const Commande& commande)
{
    std::string statut;
    if (commande.statut_ == CommandeStatut::LIVRE) {
        statut = "Livre";
    }
    else {
        statut = "Non Livre";
    }
    os << commande.client_;
    
    for (Product produit : commande.produits_) {
        os << produit;
    }

    os << std::endl << "Statut : " << statut << std::endl;

    return os;
}


Commande::Commande(const Client& client, const CommandeStatut statut):client_(client), statut_(statut)
{
}
