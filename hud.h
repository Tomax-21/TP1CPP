#pragma once
#include "Magasin.h"

void hud(Magasin& magasin);

void menu1(Magasin& magasin);
void menu2(Magasin& magasin);

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