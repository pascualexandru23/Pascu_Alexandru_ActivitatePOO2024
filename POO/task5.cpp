#include <iostream>
#include <string>
using namespace std;

class Camion {
private:
    string marca;
    int capacitate_tone;
    int* numar_remorci;
    float consum_combustibil;
    int an_fabricatie;
    static int total_camioane;
    const string tip_combustibil;

public:
    Camion() : tip_combustibil("Motorina") {
        marca = "Necunoscut";
        capacitate_tone = 0;
        numar_remorci = new int(0);
        consum_combustibil = 0.0;
        an_fabricatie = 0;
        total_camioane++;
    }

    Camion(string marca, int capacitate, int remorci, float consum, int an) : tip_combustibil("Motorina") {
        this->marca = marca;
        this->capacitate_tone = capacitate;
        this->numar_remorci = new int(remorci);
        this->consum_combustibil = consum;
        this->an_fabricatie = an;
        total_camioane++;
    }

    ~Camion() {
        delete numar_remorci;
    }

    static void afisareTotalCamioane() {
        cout << "Total camioane: " << total_camioane << endl;
    }

    void afisareDetalii() const {
        cout << "Camion: " << marca << ", Capacitate: " << capacitate_tone << " tone, Numar remorci: "
            << *numar_remorci << ", Consum combustibil: " << consum_combustibil << " L/100km, An fabricatie: "
            << an_fabricatie << ", Tip combustibil: " << tip_combustibil << endl;
    }

    void citire() {
        cout << "Introduceti marca camionului: ";
        cin >> marca;
        cout << "Introduceti capacitatea camionului (tone): ";
        cin >> capacitate_tone;
        cout << "Introduceti numarul de remorci: ";
        cin >> *numar_remorci;
        cout << "Introduceti consumul camionului (L/100km): ";
        cin >> consum_combustibil;
        cout << "Introduceti anul fabricatiei: ";
        cin >> an_fabricatie;
    }
};
int Camion::total_camioane = 0;

class Motocicleta {
private:
    string marca;
    int cilindree;
    bool este_electric;
    float consum_combustibil;
    int an_fabricatie;
    static int total_motociclete;

public:
    Motocicleta() : marca("Necunoscuta"), cilindree(0), este_electric(false), consum_combustibil(0.0), an_fabricatie(0) {
        total_motociclete++;
    }

    Motocicleta(string marca, int cilindree, bool electric, float consum, int an) : marca(marca), cilindree(cilindree),
        este_electric(electric), consum_combustibil(consum), an_fabricatie(an) {
        total_motociclete++;
    }

    static void afisareTotalMotociclete() {
        cout << "Total motociclete: " << total_motociclete << endl;
    }

    void afisareDetalii() const {
        cout << "Motocicleta: " << marca << ", Cilindree: " << cilindree << "cc, Electric: "
            << (este_electric ? "Da" : "Nu") << ", Consum combustibil: " << consum_combustibil << " L/100km, An fabricatie: "
            << an_fabricatie << endl;
    }

    void citire() {
        cout << "Introduceti marca motocicletei: ";
        cin >> marca;
        cout << "Introduceti cilindreea motocicletei (cc): ";
        cin >> cilindree;
        cout << "Este motocicleta electrica (1 - Da, 0 - Nu): ";
        cin >> este_electric;
        cout << "Introduceti consumul motocicletei (L/100km): ";
        cin >> consum_combustibil;
        cout << "Introduceti anul fabricatiei: ";
        cin >> an_fabricatie;
    }
};
int Motocicleta::total_motociclete = 0;

class Masina {
private:
    string marca;
    int numar_locuri;
    float motor_capacity;
    bool este_electric;
    static int total_masini;

public:
    Masina() : marca("Necunoscuta"), numar_locuri(0), motor_capacity(0.0), este_electric(false) {
        total_masini++;
    }

    Masina(string marca, int locuri, float capacitate_motor, bool electric) : marca(marca), numar_locuri(locuri),
        motor_capacity(capacitate_motor), este_electric(electric) {
        total_masini++;
    }

    static void afisareTotalMasini() {
        cout << "Total masini: " << total_masini << endl;
    }

    void afisareDetalii() const {
        cout << "Masina: " << marca << ", Locuri: " << numar_locuri << ", Capacitate motor: "
            << motor_capacity << " L, Electric: " << (este_electric ? "Da" : "Nu") << endl;
    }

    void citire() {
        cout << "Introduceti marca masinii: ";
        cin >> marca;
        cout << "Introduceti numarul de locuri: ";
        cin >> numar_locuri;
        cout << "Introduceti capacitatea motorului (L): ";
        cin >> motor_capacity;
        cout << "Este masina electrica (1 - Da, 0 - Nu): ";
        cin >> este_electric;
    }
};
int Masina::total_masini = 0;

int main() {

    int n_camioane, n_motociclete, n_masini;

    cout << "Introduceti numarul de camioane: ";
    cin >> n_camioane;
    Camion* camioane = new Camion[n_camioane];
    for (int i = 0; i < n_camioane; ++i) {
        cout << "Introduceti detalii pentru camionul " << i + 1 << ":\n";
        camioane[i].citire();
    }

    cout << "\nIntroduceti numarul de motociclete: ";
    cin >> n_motociclete;
    Motocicleta* motociclete = new Motocicleta[n_motociclete];
    for (int i = 0; i < n_motociclete; ++i) {
        cout << "Introduceti detalii pentru motocicleta " << i + 1 << ":\n";
        motociclete[i].citire();
    }

    cout << "\nIntroduceti numarul de masini: ";
    cin >> n_masini;
    Masina* masini = new Masina[n_masini];
    for (int i = 0; i < n_masini; ++i) {
        cout << "Introduceti detalii pentru masina " << i + 1 << ":\n";
        masini[i].citire();
    }


    cout << "\nDetalii Camioane:\n";
    for (int i = 0; i < n_camioane; ++i) {
        camioane[i].afisareDetalii();
    }

    cout << "\nDetalii Motociclete:\n";
    for (int i = 0; i < n_motociclete; ++i) {
        motociclete[i].afisareDetalii();
    }

    cout << "\nDetalii Masini:\n";
    for (int i = 0; i < n_masini; ++i) {
        masini[i].afisareDetalii();
    }


    int n_linii, n_coloane;
    cout << "\nIntroduceti dimensiunile matricii (linii si coloane): ";
    cin >> n_linii >> n_coloane;

    Masina** matrice_masini = new Masina * [n_linii];
    for (int i = 0; i < n_linii; ++i) {
        matrice_masini[i] = new Masina[n_coloane];
        for (int j = 0; j < n_coloane; ++j) {
            cout << "Introduceti detalii pentru masina " << i + 1 << "," << j + 1 << ":\n";
            matrice_masini[i][j].citire();
        }
    }

    cout << "\nMatrice de masini:\n";
    for (int i = 0; i < n_linii; ++i) {
        for (int j = 0; j < n_coloane; ++j) {
            matrice_masini[i][j].afisareDetalii();
        }
    }


    delete[] camioane;
    delete[] motociclete;
    delete[] masini;

    for (int i = 0; i < n_linii; ++i) {
        delete[] matrice_masini[i];
    }
    delete[] matrice_masini;

    return 0;
}