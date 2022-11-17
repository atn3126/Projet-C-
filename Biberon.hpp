#pragma once
#include<iostream>
using namespace std;

class biberon {


protected:

	string label;

	int heure_de_prise;
	int interval_de_rappelle;
	int quantite_max;
	int quantite_min;
	int volume_bib;
	bool reg = false;


public:

	biberon(string label, int interval_de_rappelle, int heure_de_prise, int volume_bib, int quantite_max, int quantite_min);

	void biberon_modif_quantite_min(int quantite_min);

	void biberon_rajout_heure(int ajt_heure);

	void biberon_regurgite(bool quest_regurgite);

	string label();
}



//objectif : rajouter une heure de prise
//si heure actu = heure_de prise + intervalle_de_rappel alors
//afficcher("c'est lheure de donner le bib")