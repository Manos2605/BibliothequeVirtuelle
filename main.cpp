#include <iostream>
#include "header/fonctions.h"

int main(int argc, char** argv) {
    Bibliotheque bibliotheque;
    bibliotheque.prochainId = 1;
    int choix;

    do {
        afficherMenu();
        std::cin >> choix;
        std::cin.ignore();

        switch (choix) {
            case 1:
                ajouterLivre(bibliotheque);
                break;
            case 2:
                afficherLivres(bibliotheque);
                break;
            case 3:
                rechercherLivre(bibliotheque);
                break;
            case 4:
                emprunterLivre(bibliotheque);
                break;
            case 5:
                rendreLivre(bibliotheque);
                break;
            case 6:
                std::cout << "Sauvegarde et sortie en cours...\n";
                // Ajouter la sauvegarde dans un fichier ici
                break;
            case 7:
                std::cout << "Chargement depuis un fichier en cours...\n";
                // Ajouter le chargement depuis un fichier ici
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer.\n";
                break;
        
        }
        
    } while (choix!= 6);

    return 0;
}