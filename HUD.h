#pragma once
#include "Magasin.h"

void hud(Magasin& magasin);

void menu1(Magasin& magasin);
void menu2(Magasin& magasin);
void menu3(Magasin& magasin);

void manage_panier_client(Magasin& magasin);


void create_client_hud(Magasin& magasin);
void add_product_hud(Magasin& magasin);

void research_client_hud(Magasin& magasin);
void show_all_clients_hud(Magasin& magasin);
void show_all_products_hud(Magasin& magasin);
void show_all_commandes_hud(Magasin& magasin);

void modify_product_quantity_hud(Magasin& magasin);
void show_product(Magasin& magasin);

void modify_client_hud(Magasin& magasin);

void delete_client_hud(Magasin& magasin);


void add_product_to_card_hud(Magasin& magasin, Client& client);
void show_client_cart_hud(Client& client);
void remove_product_to_card_hud(Magasin& magasin, Client& client);
void modify_quantity_product_cart_client_hud(Magasin& magasin, Client& client);


void create_commande_hud(Magasin& magasin);