#pragma once

#include "Page.h"
class Menu
{
public:
	Menu();
	void setInput(char entry);
	void refresh();
	~Menu();
protected:
	char input;
	uint8_t page;
	uint8_t cursor;
	String contenu[3][5]{
		{ "MENU", "Capteurs", "Configurer","Nourrir","Fermer la pompe" },				//Page principal
		{ "CAPTEURS", "Temp�rature eau","Temperature sol","Humidit�","Luminosit�" },	//Capteurs
		{ "CONFIGURER","Heure","Luminosit�","Fr�quence des repas","Heure des repas" },	//Configurer
	};
	
};
 
