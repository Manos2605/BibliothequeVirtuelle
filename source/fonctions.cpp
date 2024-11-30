#include "../header/fonctions.h"

void afficherMenu() {
    std::cout << "=== Gestionnaire de Bibliotheque ===\n";
    std::cout << "1. Ajouter un livre\n";
    std::cout << "2. Afficher la liste des livres\n";
    std::cout << "3. Rechercher un livre\n";
    std::cout << "4. Emprunter un livre\n";
    std::cout << "5. Rendre un livre\n";
    std::cout << "6. Sauvegarder et quitter\n";
    std::cout << "7. Charger depuis un fichier\n";
    std::cout << "Entrez votre choix : ";
}

Livre creerLivre(int id) {
    Livre nouveauLivre;
    nouveauLivre.id = id;

    std::cout << "Entrez le titre du livre : ";
    std::cin >> nouveauLivre.titre;

    std::cout << "Entrez l'auteur du livre : ";
    std::cin >> nouveauLivre.auteur;

    std::cout << "Entrez le genre du livre : ";
    std::cin >> nouveauLivre.genre;

    std::cout << "Entrez l'annee de publication : ";
    std::cin >> nouveauLivre.annee;

    nouveauLivre.disponible = true;
    return nouveauLivre;
}

void ajouterLivre(Bibliotheque &bibliotheque) {
    char continuer;
    do {
        Livre nouveauLivre = creerLivre(bibliotheque.prochainId);

        // Vérification de l'unicité de l'ID
        for (const auto &livre : bibliotheque.livres) {
            if (livre.id == nouveauLivre.id) {
                std::cout << "Erreur : Un livre avec cet ID existe deja.\n";
                return;
            }
        }

        bibliotheque.prochainId++;

        bibliotheque.livres.push_back(nouveauLivre);
        std::cout << "Le livre a ete ajoute avec succes !\n";

        // Demander à l'utilisateur s'il veut ajouter un autre livre
        std::cout << "Voulez-vous ajouter un autre livre ? (o/n) : ";
        std::cin >> continuer;
        clear();
        std::cin.ignore(); // Pour ignorer le caractère \n restant dans le buffer

    } while (continuer == 'o' || continuer == 'O');
}

void afficherLivres(const Bibliotheque &bibliotheque) {
    if (bibliotheque.livres.empty()) {
        std::cout << "Aucun livre dans la bibliotheque.\n";
        return;
    }

    for (const auto &livre : bibliotheque.livres) {
        std::cout << "ID: " << livre.id
                  << " | Titre: \"" << livre.titre << "\""
                  << " | Auteur: " << livre.auteur
                  << " | Genre: " << livre.genre
                  << " | Annee: " << livre.annee
                  << " | Disponible: " << (livre.disponible ? "Oui" : "Non")
                  << "\n";
    }
}

void rechercherLivre(const Bibliotheque &bibliotheque) {
    int choix;
    std::string critere;

    std::cout << "Rechercher un livre par :\n";
    std::cout << "1. Titre\n2. Auteur\n3. Genre\n4. Annee\n";
    std::cout << "Entrez votre choix : ";
    std::cin >> choix;
    std::cin.ignore();

    std::cout << "Entrez le critere de recherche : ";
    std::cin >> critere;

    bool trouve = false;
    for (const auto &livre : bibliotheque.livres) {
        if ((choix == 1 && livre.titre == critere) ||
            (choix == 2 && livre.auteur == critere) ||
            (choix == 3 && livre.genre == critere) ||
            (choix == 4 && std::to_string(livre.annee) == critere)) {
            std::cout << "ID: " << livre.id
                      << " | Titre: \"" << livre.titre << "\""
                      << " | Auteur: " << livre.auteur
                      << " | Genre: " << livre.genre
                      << " | Annee: " << livre.annee
                      << " | Disponible: " << (livre.disponible ? "Oui" : "Non")
                      << "\n";
            trouve = true;
        }
    }

    if (!trouve) {
        std::cout << "Aucun livre ne correspond au critere.\n";
    }
}

void emprunterLivre(Bibliotheque &bibliotheque) {
    int id;
    std::cout << "Entrez l'ID du livre a emprunter : ";
    std::cin >> id;

    for (auto &livre : bibliotheque.livres) {
        if (livre.id == id) {
            if (livre.disponible) {
                livre.disponible = false;
                std::cout << "Livre emprunte avec succes !\n";
            } else {
                std::cout << "Ce livre est deja emprunte.\n";
            }
            return;
        }
    }

    std::cout << "Aucun livre avec cet ID n'a ete trouve.\n";
}

void rendreLivre(Bibliotheque &bibliotheque) {
    int id;
    std::cout << "Entrez l'ID du livre à rendre : ";
    std::cin >> id;

    for (auto &livre : bibliotheque.livres) {
        if (livre.id == id) {
            if (!livre.disponible) {
                livre.disponible = true;
                std::cout << "Livre rendu avec succes !\n";
            } else {
                std::cout << "Ce livre n'est pas emprunte.\n";
            }
            return;
        }
    }

    std::cout << "Aucun livre avec cet ID n'a ete trouve.\n";
}

void clear() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}