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
	string codeEtoile = "";
	string nom = "";
	int diametre = 0;
};

struct Etoile {
	string code = "";
	string nom = "";
	int nbPlanetes = 0;							//Variable � utiliser dans la fonctions ajouterPlanetesAuxEtoiles pour incr�menter le nombre de plan�tes ajout�s � l'�toile.								
	Planete planetes[MAX_PLANETES];	//Tableau des plan�tes de l'�toile.  Ici on suppose qu'il y a maximum 8 plan�tes par syst�me (donc pour certaines �toiles, il y aura des cases vides).
};


/*
* Fonction remplissant un tableau d'�toiles � partir d'un fichier CSV
* ATTENTION: Ne pas changer la signature de la fonction
*/
void lireEtoiles(Etoile etoiles[], int nombreEtoiles) {

}


/*
* Fonction remplissant un tableau de plan�tes � partir d'un fichier CSV
* ATTENTION: Ne pas changer la signature de la fonction
*/
void lirePlanetes(Planete planetes[], int nombrePlanetes) {

}


/*
* Fonction permettant d'ajouter les bonnes plan�tes � chaque �toile
* afin que chaque �toile poss�de ses propres plan�tes.
* ASTUCE: Utiliser la variable nbPlanetes de la structure Etoile pour incr�menter le nombre de plan�tes ajout�es � l'�toile.
* ATTENTION: Ne pas changer la signature de la fonction
*/
void ajouterPlanetesAuxEtoiles(Planete planetes[], int taillePlanetes, Etoile etoiles[], int tailleEtoiles) {

}


/*
* Fonction permettant d'afficher les �toiles et leurs plan�tes dans un format sp�cifique
* ATTENTION: Ne pas changer la signature de la fonction
*/
void afficherEtoiles(Etoile etoiles[], int tailleEtoiles) {

}


/*
* Fonction repr�sentant l'algorithme de StarWars
* ATTENTION: Ne rien changer � cette fonction
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

