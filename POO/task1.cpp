#include <iostream>
#include <string>
using namespace std;


struct Bloc {
    string strada;
    int numarStrada;
    int numarScari;
    int numarApartamente;
    int anConstructie;
};

Bloc citesteBloc() {
    Bloc bloc;
    cout << "Introduceti strada: ";
    cin >> bloc.strada;
    cout << "Introduceti numarul strazii: ";
    cin >> bloc.numarStrada;
    cout << "Introduceti numarul de scari: ";
    cin >> bloc.numarScari;
    cout << "Introduceti numarul total de apartamente: ";
    cin >> bloc.numarApartamente;
    cout << "Introduceti anul constructiei: ";
    cin >> bloc.anConstructie;
    return bloc;
}
void afiseazaBloc(const Bloc& bloc) {
    cout << "Blocul de pe strada " << bloc.strada
        << " numarul " << bloc.numarStrada
        << ", are " << bloc.numarScari << " scari, "
        << "un numar total de " << bloc.numarApartamente << " apartamente "
        << "si a fost construit in anul " << bloc.anConstructie << endl;
}

int main() {
    const int numarBlocuri = 10;
    Bloc blocuri[numarBlocuri];

    // Citirea valorilor pentru fiecare bloc
    for (int i = 0; i < numarBlocuri; ++i) {
        cout << "Cititi informatiile pentru blocul " << i + 1 << endl;
        blocuri[i] = citesteBloc();
    }

    // Afisarea valorilor pentru fiecare bloc
    cout << endl << "Informatii despre blocuri:" << endl;
    for (int i = 0; i < numarBlocuri; ++i) {
        afiseazaBloc(blocuri[i]);
    }

    return 0;
}