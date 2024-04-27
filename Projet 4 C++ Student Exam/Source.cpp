#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure pour représenter un étudiant
struct Etudiant {
    string nom;
    string prenom;
    string codePermanent;
    int anneeNaissance;
    string programmeEtude;
    string departement;
    float notes[4];
    float moyenne;
};

// Fonction pour calculer la moyenne d'un etudiant
void calculerMoyenne(Etudiant& etudiant) {
    float somme = 0;
    for (int i = 0; i < 4; ++i) {
        somme += etudiant.notes[i];
    }
    etudiant.moyenne = somme / 4.0;
}

// Fonction pour vérifier si un étudiant est né une année donnée
bool estNeCetteAnnee(const Etudiant& etudiant, int annee) {
    return etudiant.anneeNaissance == annee;
}

// Fonction pour afficher les informations d'un étudiant pour un département donné
void afficherSiDepartement(const Etudiant& etudiant, const string& departement) {
    if (etudiant.departement == departement) {
        cout << "Nom: " << etudiant.nom << endl;
        cout << "Prenom: " << etudiant.prenom << endl;
        cout << "Code Permanent: " << etudiant.codePermanent << endl;
        cout << "Annee de naissance: " << etudiant.anneeNaissance << endl;
        cout << "Programme d'etude: " << etudiant.programmeEtude << endl;
        cout << "Departement: " << etudiant.departement << endl;
        cout << "Moyenne: " << etudiant.moyenne << endl;
        cout << endl;
    }
}

// Fonction pour afficher les informations d'un étudiant pour un programme donné
void afficherSiProgramme(const Etudiant& etudiant, const string& programme) {
    if (etudiant.programmeEtude == programme) {
        cout << "Nom: " << etudiant.nom << endl;
        cout << "Prenom: " << etudiant.prenom << endl;
        cout << "Code Permanent: " << etudiant.codePermanent << endl;
        cout << "Annee de naissance: " << etudiant.anneeNaissance << endl;
        cout << "Programme d'etude: " << etudiant.programmeEtude << endl;
        cout << "Departement: " << etudiant.departement << endl;
        cout << "Moyenne: " << etudiant.moyenne << endl;
        cout << endl;
    }
}

int main() {
    // Lecture des données à partir du fichier
    ifstream fichier("etudiants.txt");
    Etudiant etudiants[10];

    for (int i = 0; i < 10; ++i) {
        fichier >> etudiants[i].nom >> etudiants[i].prenom >> etudiants[i].codePermanent >> etudiants[i].anneeNaissance >> etudiants[i].programmeEtude >> etudiants[i].departement;
        for (int j = 0; j < 4; ++j) {
            fichier >> etudiants[i].notes[j];
        }
        calculerMoyenne(etudiants[i]); // Calcul de la moyenne
    }
    fichier.close();

    // Menu Accueil
    int choix = 0;
    while (choix != 4) {
        cout << "Menu:" << endl;
        cout << "1. Afficher les etudiants nees une annee particuliere" << endl;
        cout << "2. Afficher les etudiants affilies a un programme particulier" << endl;
        cout << "3. Afficher les etudiants d'un departement particulier" << endl;
        cout << "4. Quitter" << endl;
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
        case 1: {
            int annee;
            cout << "Entrez l'annee de naissance : ";
            cin >> annee;
            cout << "Etudiants nes en " << annee << ":" << endl;
            for (const Etudiant& etudiant : etudiants) {
                if (estNeCetteAnnee(etudiant, annee)) {
                    cout << etudiant.nom << " " << etudiant.prenom << endl;
                }
            }
            break;
        }
        case 2: {
            string programme;
            cout << "Entrez le programme d'etude : ";
            cin >> programme;
            cout << "Etudiants du programme " << programme << ":" << endl;
            for (const Etudiant& etudiant : etudiants) {
                afficherSiProgramme(etudiant, programme);
            }
            break;
        }
        case 3: {
            string departement;
            cout << "Entrez le departement : ";
            cin >> departement;
            cout << "Etudiants du departement " << departement << ":" << endl;
            for (const Etudiant& etudiant : etudiants) {
                afficherSiDepartement(etudiant, departement);
            }
            break;
        }
        case 4:
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez reessayer." << endl;
        }
    }

    return 0;
}