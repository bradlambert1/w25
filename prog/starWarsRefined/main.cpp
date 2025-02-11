#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <format>
using namespace std;

const string FICHIER_PLANETES = "planetes.csv";
const string FICHIER_ETOILES = "etoiles.csv";
const int MAX_PLANETES = 8;
const int NOMBRE_PLANETES = 32;
const int NOMBRE_ETOILES = 5;
const int PI = 3.14159;

struct Planete {
	string codeEtoile = "";
	string nom = "";
	int diametre = 0;
};

struct Etoile {
	string code = "";
	string nom = "";
	int nbPlanetes = 0;							//Variable à utiliser dans la fonctions ajouterPlanetesAuxEtoiles pour incrémenter le nombre de planètes ajoutés à l'étoile.								
	Planete planetes[MAX_PLANETES];	//Tableau des planètes de l'étoile.  Ici on suppose qu'il y a maximum 8 planètes par système (donc pour certaines étoiles, il y aura des cases vides).
};


/*
* Fonction remplissant un tableau d'étoiles à partir d'un fichier CSV
* ATTENTION: Ne pas changer la signature de la fonction
*/
void lireEtoiles(Etoile etoiles[], int nombreEtoiles) {
	fstream fichier;
	fichier.open(FICHIER_ETOILES, ios::in);

	string code; string nom; string ligne;
	int i = 0; // counter for alternating between name and codename
    int j = 0; // num of stars
	while (getline(fichier, ligne, ',')) {
		if (i % 2 == 0) {
			etoiles[j].code = ligne;
		}
		else {
			etoiles[j].nom = ligne;
            j++;
		}
            i++;
	};
	fichier.close();
}


/*
* Fonction remplissant un tableau de planètes à partir d'un fichier CSV
* ATTENTION: Ne pas changer la signature de la fonction
*/
void lirePlanetes(Planete planetes[], int nombrePlanetes) {
	fstream fichier;
	fichier.open("planetes.csv");


	string code; string nom; string ligne;
	int i = 0; // counter for alternating between name and codename
    int j = 0; // num of stars
	while (getline(fichier, ligne, ',')) {
		if (i % 3 == 0) {
			planetes[j].codeEtoile = ligne;
		} else if (i % 3 == 1) {
            planetes[j].nom = ligne;
        }
		else {
			planetes[j].diametre = stoi(ligne);
            j++;
		}
            i++;
	};
	fichier.close();
}


/*
* Fonction permettant d'ajouter les bonnes planètes à chaque étoile
* afin que chaque étoile possède ses propres planètes.
* ASTUCE: Utiliser la variable nbPlanetes de la structure Etoile pour incrémenter le nombre de planètes ajoutées à l'étoile.
* ATTENTION: Ne pas changer la signature de la fonction
*/
void ajouterPlanetesAuxEtoiles(Planete planetes[], int taillePlanetes, Etoile etoiles[], int tailleEtoiles) {
    Planete goodPlanet; int planetsAdded = 0;
    for (int starCount = 0; starCount < tailleEtoiles; starCount++) {
        for (int planetCount = 0; planetCount < taillePlanetes; planetCount++) {
            if (planetes[planetCount].codeEtoile == etoiles[starCount].code) {
                goodPlanet = planetes[planetCount];
                etoiles[starCount].planetes[planetsAdded] = goodPlanet;
                planetsAdded++;
            }
        }
    planetsAdded = 0;
    }
}


/*
* Fonction permettant d'afficher les étoiles et leurs planètes dans un format spécifique
* ATTENTION: Ne pas changer la signature de la fonction
*/
void afficherEtoiles(Etoile etoiles[], int tailleEtoiles) {
    string stringOne;
    string stringTwo;
    string stringThree;
    cout << "--------------------------------------------"<< endl;
    cout << "| StarWars - Les étoiles et leurs planètes |"<< endl;
    cout << "--------------------------------------------"<< endl << endl;
    for (int i = 0; i < tailleEtoiles; i++) {
        cout << "--------------------------------------------"<< endl;
        cout << "| PLANETE  | DIAMETRE (km)  | VOLUME (km3) |"<< endl;
        cout << "--------------------------------------------"<< endl << endl;
        for (int j = 0; i < NOMBRE_PLANETES; j++) {
            stringOne = etoiles[i].planetes[j].nom;
            stringTwo = etoiles[i].planetes[j].diametre;
            stringThree = (pow(((etoiles[i].planetes[j].diametre)/2), 2) * 3.14 * 4) / 3;
            cout << format("|{}        | {}             | {}            ", stringOne, stringTwo, stringThree )
        };
        cout << "--------------------------------------------"<< endl << endl;
    }
}


/*
* Fonction représentant l'algorithme de StarWars
* ATTENTION: Ne rien changer à cette fonction
*/
void starWars() {
	Etoile etoiles[NOMBRE_ETOILES];
	lireEtoiles(etoiles, NOMBRE_ETOILES);

	Planete planetes[NOMBRE_PLANETES];
	lirePlanetes(planetes, NOMBRE_PLANETES);

	ajouterPlanetesAuxEtoiles(planetes, NOMBRE_PLANETES, etoiles, NOMBRE_ETOILES);

	afficherEtoiles(etoiles, NOMBRE_ETOILES);
}


/*
* Fonction principale du programme
*/
int main() {
	setlocale(LC_ALL, "");
	setlocale(LC_NUMERIC, "C");
	srand((unsigned int)time(NULL));

	starWars();
	return 0;
}

