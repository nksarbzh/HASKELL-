#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Evenement { 
    string nom;
    string heuredebut;
    string heurefin;
};

void afficherMenu(){
    cout << " Menu : " << endl;
    cout << " \n " << endl;
    cout << " 1.Creer un emplois du temps " << endl;
    cout << " \n " << endl;
    cout << " 2.Afficher l'emploi du temps " << endl;
    cout << " \n " << endl;
    cout << " 3.Supprimer ou ajouter un element de l'emploi du temps " << endl;
    cout << " \n " << endl;
    cout << " 0.Quitter l'application " << endl;
    cout << " \n " << endl;
    cout << " Que souhaitez vous faire ? : " << endl;
}

void CreerEmploiDuTemps(vector<Evenement>& emploi) {
    emploi.clear(); // reinitialiser l'emploi du temps
    int n;
    string date;
    cout << " Entre la date (J/M/A) : " << endl;
    cin >> date;
    cout << " \n " << endl;
    cout << " Combien d'evenements souhaitez vous creer ? : " << endl;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Evenement e;
        cout << " \n " << endl;
        cout << " Nom de l'evenement " << i + 1 << " : " << endl;
        getline(std::cin, e.nom); 
        cout << " \n " << endl;
        cout << " Heure de debut : " << endl;
        getline(std::cin, e.heuredebut);
        cout << " \n " << endl;
        cout << " Heure de fin : " << endl;
        getline(std::cin, e.heurefin);
        emploi.push_back(e);
    }
}

void afficherEmploiDuTemps(const vector<Evenement>& emploi) {
    if (emploi.empty()) {
        cout << " Aucun evenement enregistre." << endl;
        return;
    }
    cout << " EMPLOI DU TEMPS " << endl;
    for (const auto& e : emploi) {
        cout << e.heuredebut << " h " << " a " << e.heurefin << " h " << " : " << e.nom << endl;
    }
}

void modifierEmploiDuTemps(vector<Evenement>& emploi) {
    int choix;
    cout << " 1.Ajouter un element ! " << endl;
    cout << " \n " << endl;
    cout << " 2.Supprimer un element ! " << endl;
    cout << " \n " << endl;
    cin >> choix;
    cin.ignore();

    if (choix == 1) {
        Evenement e;
        cout << " Nom : " << endl;
        getline(cin, e.nom);
        cout << " \n " << endl;
        cout << " Heure de debut : " << endl;
        getline(cin, e.heuredebut);
        cout << " \n " << endl;
        cout << " Heure de fin : " << endl;
        getline(cin, e.heurefin);
        cout << " \n " << endl;
        emploi.push_back(e);
        cout << " Evenement ajoute." << endl;
        cout << " \n " << endl;
    } else if (choix == 2){
        afficherEmploiDuTemps(emploi);
        cout << "  Entrer l'indice a partir de l'evenement a supprimer : " << endl;
        int index;
        cin >> index;
        cin.ignore();
        cout << " \n " << endl;
        if (index > 0 && index <= emploi.size()) {
            emploi.erase(emploi.begin() + index - 1);
            cout << " Evenement supprime." << endl;
        }
        else {
            cout << " Indice inValide ! " << endl;
        }
    }
    else {
        cout << " Choix invalide ! " << endl;
    }
}

int main(){
    vector<Evenement> emploi;
    int choix;
    cout << " Bienvenue sur notre application ! " << endl;
    cout << " \n " << endl;
    do {
        cout << " \n" << endl;
        afficherMenu();
        cin >> choix;
        cin.ignore();
        cout << " \n" << endl;
        switch (choix) {
        case 1:
            CreerEmploiDuTemps(emploi);
            break;
        case 2:
            afficherEmploiDuTemps(emploi);
            break;
        case 3:
            modifierEmploiDuTemps(emploi);
            break;
        case 0:
            cout << " Merci d'avoir consulter notre application. Au revoir ! " << endl;
            break;
        default :
                cout << " Choix invalide ! " << endl;
        }
    } while (choix != 0);
              
    return 0;

}
