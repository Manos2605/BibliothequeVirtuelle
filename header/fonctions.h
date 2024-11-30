#include <iostream>
#include <vector>
#include <string>

struct Livre {
    int id;
    std::string titre;
    std::string auteur;
    std::string genre;
    int annee;
    bool disponible;
};

struct Bibliotheque {
    std::vector<Livre> livres;
    int prochainId; 
};

#ifndef FONCTIONS_H
#define FONCTIONS_H

void afficherMenu();
Livre creerLivre();
void ajouterLivre(Bibliotheque &bibliotheque);
void rechercherLivre(const Bibliotheque &bibliotheque);
void afficherLivres(const Bibliotheque &bibliotheque);
void emprunterLivre(Bibliotheque &bibliotheque);
void rendreLivre(Bibliotheque &bibliotheque);
void clear();

#endif

