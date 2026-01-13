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
    os <<"id : " << commande.id_ << std::endl;

    return os;
}


Commande::Commande(const Client& client, const CommandeStatut statut):id_(generate_random_product_id()), client_(client), statut_(statut)
{
}

Commande::Commande(const unsigned int& id, const Client& client, const std::vector<Product>& produits, const CommandeStatut statut):
    id_(id), client_(client), produits_(produits), statut_(statut)
{
}

Commande::Commande(const Client& client) :id_(generate_random_product_id()), client_(client), statut_(CommandeStatut::NON_LIVRE)
{
}

void Commande::setStatut(const CommandeStatut& statut)
{
    statut_ = statut;
}

void Commande::addProduct(const Product& product)
{
    produits_.push_back(product);
}

Client Commande::client()
{
    return client_;
}

unsigned int Commande::id()
{
    return id_;
}

CommandeStatut Commande::statut()
{
    return statut_;
}

std::vector<Product> Commande::produits()
{
    return produits_;
}

std::string Commande::string_statut()
{
    if (statut_ == CommandeStatut::LIVRE) {
        return "Livre";
    }
    else {
        return "Non livre";
    }
}
