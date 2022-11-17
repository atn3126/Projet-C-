
#include "Biberon.hpp"
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

	//modifier le volume du biberon donner ou a donner
	void modif_volum_bib(int modif_volume_bib) {
		this->volume_bib = modif_volume_bib;

		cout << "effectue quantite_max\n";
	}


	//modifier le volume max du bib
	void biberon_modif_quantite_max(int quantite_max) {
		this->quantite_max = quantite_max;

		cout << "effectue quantite_max\n";
	}

	//modifier le volume max du bib
	void biberon_modif_quantite_min(int quantite_min) {
		this->quantite_min = quantite_min;

		cout << "effectue quantite_min\n";
	}

	//ajout d'une heure de prise de bib
	void biberon_rajout_heure(int ajt_heure) {
		this->heure_de_prise = ajt_heure;

		cout << "effectue ajt_heure\n";
	}

	//effectue un demande pour savoir si le bébé a vomis
	void biberon_regurgite(bool quest_regurgite) {
		this->reg = quest_regurgite;

		cout << "effectue regurgite\n";
	}


	//retourne la notification
	string label(){
		return this->label;
	}