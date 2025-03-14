#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

const string FICHIER_PLANETES = "planetes.csv";
const string FICHIER_ETOILES = "etoiles.csv";
const int MAX_PLANETES = 8;
const int NOMBRE_PLANETES = 32;
const int NOMBRE_ETOILES = 5;
const float PI = 3.14159;

struct Planete {
private:
	string codeEtoile = "";
	string nom = "";
	int diametre = 0;
	
	long long volume() {
		return (4.0 / 3.0) * PI * pow((diametre / 2.0), 3);
	}
	static int count;

public:
	static void lirePlanetes(Planete planetes[]) {
		ifstream fichier(FICHIER_PLANETES);
		string donnee;
		for (int i = 0; i < NOMBRE_PLANETES; i++) {
			getline(fichier, donnee, ',');
			planetes[i].codeEtoile = donnee;
			getline(fichier, donnee, ',');
			planetes[i].nom = donnee;
			getline(fichier, donnee);
			planetes[i].diametre = stoi(donnee);
			count++;
		}
	}

	string getCodeEtoile() {
		return codeEtoile;
	}
	string getName() {
		return nom;
	}
	int getDiameter() {
		return diametre;
	}
	long long getVolume() {
		return volume();
	}
	static int getCount() {
		return count;
	}
};


struct Etoile {
private:
	string code = "";
	string nom = "";
	int nbPlanetes = 0;
	Planete planetes[MAX_PLANETES];
	static int count;

public:

	static void lireEtoiles(Etoile etoiles[]) {
		ifstream fichier(FICHIER_ETOILES);
		string donnee;
		for (int i = 0; i < NOMBRE_ETOILES; i++) {
			getline(fichier, donnee, ',');
			etoiles[i].code = donnee;
			getline(fichier, donnee);
			etoiles[i].nom = donnee;
			count++;
		}
	}

	void ajouterPlanetesAuxEtoiles(Planete planetes[], int taillePlanetes) {
		for (int j = 0; j < taillePlanetes; j++) {
			if (this->code == planetes[j].getCodeEtoile() && nbPlanetes < MAX_PLANETES) {
				this->planetes[nbPlanetes++] = planetes[j];
			}
		}
	}

	int getNbPlanetes() {
		return nbPlanetes;
	}
	string getName() {
		return nom;
	}
	Planete getPlanets(int i) {
		return planetes[i];
	}
	static int getCount() {
		return count;
	}
};
int Etoile::count = 0; 
int Planete::count = 0;

void afficherEtoiles(Etoile etoiles[], int tailleEtoiles) {
	cout << "----------------------------------------------------" << endl;
	cout << "|     StarWars - Les Ã©toiles et leurs planÃ¨tes     |" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < tailleEtoiles; i++) {
		cout << endl;
		cout << etoiles[i].getName() << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "| " << setw(13) << left << "PLANÃˆTE" << " | " << setw(13) << left << "DIAMÃˆTRE (km)" << " | " << setw(16) << "VOLUME (kmÂ³)" << " |" << endl;
		cout << "----------------------------------------------------" << endl;
		for (int j = 0; j < etoiles[i].getNbPlanetes(); j++) {
			cout << "| " << setw(13) << left << etoiles[i].getPlanets(j).getName() << " | " << setw(13) << right << etoiles[i].getPlanets(j).getDiameter() << " | " << setw(16) << right << etoiles[i].getPlanets(j).getVolume() << " |" << endl;
		}
		cout << "----------------------------------------------------" << endl;
	}
	cout << "Nombre etoiles: " << Etoile::getCount() << endl; 
	cout << "Nombre planetes: " << Planete::getCount() << endl; 
}

void starWars() {
	Planete planetes[NOMBRE_PLANETES];
	Planete::lirePlanetes(planetes);

	Etoile etoiles[NOMBRE_ETOILES];
	Etoile::lireEtoiles(etoiles);

	for (int i = 0; i < NOMBRE_ETOILES; i++) {
		etoiles[i].ajouterPlanetesAuxEtoiles(planetes, NOMBRE_PLANETES);
	}

	afficherEtoiles(etoiles, NOMBRE_ETOILES);
}

int main() {
	setlocale(LC_ALL, "");
	setlocale(LC_NUMERIC, "C");
	srand((unsigned int)time(NULL));

	starWars();
	return 0;
}
