#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 

class Camion {
public:
    string marca;
    int capacitate_tone;
    int* numar_remorci;
    float consum_combustibil;
    int an_fabricatie;
    static int total_camioane;
    const string tip_combustibil;

    Camion() : tip_combustibil("Motorina") {
        marca = "Necunoscut";
        capacitate_tone = 0;
        numar_remorci = new int(0);
        consum_combustibil = 0.0;
        an_fabricatie = 0;
        total_camioane++;
    }

    Camion(string marca, int capacitate) : tip_combustibil("Motorina") {
        this->marca = marca;
        this->capacitate_tone = capacitate;
        this->numar_remorci = new int(0);
        this->consum_combustibil = 0.0;
        this->an_fabricatie = 0;
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

    static void afisareTotalCamioane() {
        cout << "Total camioane: " << total_camioane << endl;
    }
    void afisareDetalii() {
        cout << "Camion: " << marca << ", Capacitate: " << capacitate_tone << " tone, Numar remorci: "
            << *numar_remorci << ", Consum combustibil: " << consum_combustibil << " L/100km, An fabricatie: "
            << an_fabricatie << ", Tip combustibil: " << tip_combustibil << endl;
    }

    ~Camion() {
        delete numar_remorci;
    }
};

int Camion::total_camioane = 0;

class Masina {
public:
    string marca;
    int numar_usi;
    int* viteza_maxima;
    float capacitate_motor;
    int an_fabricatie;
    static int total_masini;
    const string tip_combustibil;

    Masina() : tip_combustibil("Benzina") {
        marca = "Necunoscut";
        numar_usi = 0;
        viteza_maxima = new int(0);
        capacitate_motor = 0.0;
        an_fabricatie = 0;
        total_masini++;
    }

    Masina(string marca, int numar_usi) : tip_combustibil("Benzina") {
        this->marca = marca;
        this->numar_usi = numar_usi;
        this->viteza_maxima = new int(0);
        this->capacitate_motor = 0.0;
        this->an_fabricatie = 0;
        total_masini++;
    }

    Masina(string marca, int numar_usi, int viteza, float capacitate, int an) : tip_combustibil("Benzina") {
        this->marca = marca;
        this->numar_usi = numar_usi;
        this->viteza_maxima = new int(viteza);
        this->capacitate_motor = capacitate;
        this->an_fabricatie = an;
        total_masini++;
    }

    static void afisareTotalMasini() {
        cout << "Total masini: " << total_masini << endl;
    }
    void afisareDetalii() {
        cout << "Masina: " << marca << ", Numar usi: " << numar_usi << ", Viteza maxima: " << *viteza_maxima
            << " km/h, Capacitate motor: " << capacitate_motor << " L, An fabricatie: " << an_fabricatie
            << ", Tip combustibil: " << tip_combustibil << endl;
    }

    ~Masina() {
        delete viteza_maxima;
    }
};

int Masina::total_masini = 0;

class Motocicleta {
public:
    string marca;
    int numar_roti;
    char* tip_motocicleta;
    float capacitate_motor;
    int an_fabricatie;
    static int total_motociclete;
    const string tip_combustibil;

    Motocicleta() : tip_combustibil("Benzina") {
        marca = "Necunoscut";
        numar_roti = 0;
        tip_motocicleta = new char[strlen("Standard") + 1];
        strcpy(tip_motocicleta, "Standard");
        capacitate_motor = 0.0;
        an_fabricatie = 0;
        total_motociclete++;
    }

    Motocicleta(string marca, int numar_roti) : tip_combustibil("Benzina") {
        this->marca = marca;
        this->numar_roti = numar_roti;
        this->tip_motocicleta = new char[strlen("Standard") + 1];
        strcpy(tip_motocicleta, "Standard");
        this->capacitate_motor = 0.0;
        this->an_fabricatie = 0;
        total_motociclete++;
    }

    Motocicleta(string marca, int numar_roti, const char* tip, float capacitate, int an) : tip_combustibil("Benzina") {
        this->marca = marca;
        this->numar_roti = numar_roti;
        this->tip_motocicleta = new char[strlen(tip) + 1];
        strcpy(this->tip_motocicleta, tip);
        this->capacitate_motor = capacitate;
        this->an_fabricatie = an;
        total_motociclete++;
    }

    static void afisareTotalMotociclete() {
        cout << "Total motociclete: " << total_motociclete << endl;
    }
    void afisareDetalii() {
        cout << "Motocicleta: " << marca << ", Numar roti: " << numar_roti << ", Tip: " << tip_motocicleta
            << ", Capacitate motor: " << capacitate_motor << " L, An fabricatie: " << an_fabricatie
            << ", Tip combustibil: " << tip_combustibil << endl;
    }

    ~Motocicleta() {
        delete[] tip_motocicleta;
    }
};

int Motocicleta::total_motociclete = 0;

int main() {
    Camion c1;
    Camion c2("Volvo", 20);
    Camion c3("Scania", 25, 2, 15.5, 2018);

    Masina m1;
    Masina m2("BMW", 4);
    Masina m3("Audi", 4, 250, 2.0, 2020);

    Motocicleta mo1;
    Motocicleta mo2("Yamaha", 2);
    Motocicleta mo3("Kawasaki", 2, "Sport", 1.2, 2019);

    c1.afisareTotalCamioane();
    m1.afisareTotalMasini();
    mo1.afisareTotalMotociclete();

    cout << "Detalii Camion 1: "; c1.afisareDetalii();
    cout << "Detalii Camion 2: "; c2.afisareDetalii();
    cout << "Detalii Camion 3: "; c3.afisareDetalii();

    cout << "Detalii Masina 1: "; m1.afisareDetalii();
    cout << "Detalii Masina 2: "; m2.afisareDetalii();
    cout << "Detalii Masina 3: "; m3.afisareDetalii();

    cout << "Detalii Motocicleta 1: "; mo1.afisareDetalii();
    cout << "Detalii Motocicleta 2: "; mo2.afisareDetalii();
    cout << "Detalii Motocicleta 3: "; mo3.afisareDetalii();



    return 0;
}