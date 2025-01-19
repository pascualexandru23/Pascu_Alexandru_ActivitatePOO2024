#include <iostream>
#include <string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS


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

    Camion(const Camion& other) : tip_combustibil("Motorina") {
        marca = other.marca;
        capacitate_tone = other.capacitate_tone;
        numar_remorci = new int(*other.numar_remorci);
        consum_combustibil = other.consum_combustibil;
        an_fabricatie = other.an_fabricatie;
        total_camioane++;
    }

    ~Camion() {
        delete numar_remorci;
    }

    static void afisareTotalCamioane() {
        cout << "Total camioane: " << total_camioane << endl;
    }

    void afisareDetalii() {
        cout << "Camion: " << marca << ", Capacitate: " << capacitate_tone << " tone, Numar remorci: "
            << *numar_remorci << ", Consum combustibil: " << consum_combustibil << " L/100km, An fabricatie: "
            << an_fabricatie << ", Tip combustibil: " << tip_combustibil << endl;
    }


    Camion& operator=(const Camion& other) {
        if (this == &other) return *this;
        marca = other.marca;
        capacitate_tone = other.capacitate_tone;
        numar_remorci = new int(*other.numar_remorci);
        consum_combustibil = other.consum_combustibil;
        an_fabricatie = other.an_fabricatie;
        return *this;
    }

    Camion operator+(const Camion& other) {
        Camion temp;
        temp.capacitate_tone = this->capacitate_tone + other.capacitate_tone;
        temp.consum_combustibil = this->consum_combustibil + other.consum_combustibil;
        return temp;
    }

    bool operator==(const Camion& other) {
        return this->capacitate_tone == other.capacitate_tone;
    }

    void operator++() {
        capacitate_tone++;
    }

    friend void prelucrareCamion(Camion& c);
};


int Camion::total_camioane = 0;


void prelucrareCamion(Camion& c) {
    c.capacitate_tone += 5;
    c.consum_combustibil += 2.0;
    cout << "Detalii dupa prelucrare:" << endl;
    c.afisareDetalii();
}


class Motocicleta {
private:
    string marca;
    int cilindree;
    bool are_haion;
    float consum_combustibil;
    int an_fabricatie;
    static int total_motociclete;
    const string tip_combustibil;

public:
    Motocicleta() : tip_combustibil("Benzina") {
        marca = "Necunoscut";
        cilindree = 0;
        are_haion = false;
        consum_combustibil = 0.0;
        an_fabricatie = 0;
        total_motociclete++;
    }

    Motocicleta(string marca, int cilindree) : tip_combustibil("Benzina") {
        this->marca = marca;
        this->cilindree = cilindree;
        this->are_haion = false;
        this->consum_combustibil = 0.0;
        this->an_fabricatie = 0;
        total_motociclete++;
    }

    Motocicleta(string marca, int cilindree, bool haion, float consum, int an) : tip_combustibil("Benzina") {
        this->marca = marca;
        this->cilindree = cilindree;
        this->are_haion = haion;
        this->consum_combustibil = consum;
        this->an_fabricatie = an;
        total_motociclete++;
    }

    Motocicleta(const Motocicleta& other) : tip_combustibil("Benzina") {
        marca = other.marca;
        cilindree = other.cilindree;
        are_haion = other.are_haion;
        consum_combustibil = other.consum_combustibil;
        an_fabricatie = other.an_fabricatie;
        total_motociclete++;
    }

    ~Motocicleta() {}

    static void afisareTotalMotociclete() {
        cout << "Total motociclete: " << total_motociclete << endl;
    }

    void afisareDetalii() {
        cout << "Motocicleta: " << marca << ", Cilindree: " << cilindree << "cc, Haion: " << (are_haion ? "Da" : "Nu")
            << ", Consum combustibil: " << consum_combustibil << " L/100km, An fabricatie: " << an_fabricatie
            << ", Tip combustibil: " << tip_combustibil << endl;
    }


    Motocicleta& operator=(const Motocicleta& other) {
        if (this == &other) return *this;
        marca = other.marca;
        cilindree = other.cilindree;
        are_haion = other.are_haion;
        consum_combustibil = other.consum_combustibil;
        an_fabricatie = other.an_fabricatie;
        return *this;
    }

    Motocicleta operator+(const Motocicleta& other) {
        Motocicleta temp;
        temp.cilindree = this->cilindree + other.cilindree;
        temp.consum_combustibil = this->consum_combustibil + other.consum_combustibil;
        return temp;
    }

    bool operator==(const Motocicleta& other) {
        return this->cilindree == other.cilindree;
    }

    void operator++() {
        cilindree++;
    }

    friend void prelucrareMotocicleta(Motocicleta& m);
};


int Motocicleta::total_motociclete = 0;


void prelucrareMotocicleta(Motocicleta& m) {
    m.cilindree += 50;
    m.consum_combustibil += 0.5;
    cout << "Detalii dupa prelucrare:" << endl;
    m.afisareDetalii();
}


class Masina {
private:
    string marca;
    int numar_locuri;
    float motor_capacity;
    bool este_electric;
    static int total_masini;

public:
    Masina() {
        marca = "Necunoscut";
        numar_locuri = 4;
        motor_capacity = 0.0;
        este_electric = false;
        total_masini++;
    }

    Masina(string marca, int locuri, float capacitate, bool electric) {
        this->marca = marca;
        this->numar_locuri = locuri;
        this->motor_capacity = capacitate;
        this->este_electric = electric;
        total_masini++;
    }

    Masina(const Masina& other) {
        marca = other.marca;
        numar_locuri = other.numar_locuri;
        motor_capacity = other.motor_capacity;
        este_electric = other.este_electric;
        total_masini++;
    }

    ~Masina() {}

    static void afisareTotalMasini() {
        cout << "Total masini: " << total_masini << endl;
    }

    void afisareDetalii() {
        cout << "Masina: " << marca << ", Locuri: " << numar_locuri << ", Capacitate motor: "
            << motor_capacity << " L, Electric: " << (este_electric ? "Da" : "Nu") << endl;
    }


    Masina& operator=(const Masina& other) {
        if (this == &other) return *this;
        marca = other.marca;
        numar_locuri = other.numar_locuri;
        motor_capacity = other.motor_capacity;
        este_electric = other.este_electric;
        return *this;
    }

    Masina operator+(const Masina& other) {
        Masina temp;
        temp.motor_capacity = this->motor_capacity + other.motor_capacity;
        temp.numar_locuri = this->numar_locuri + other.numar_locuri;
        return temp;
    }

    bool operator==(const Masina& other) {
        return this->motor_capacity == other.motor_capacity;
    }

    void operator++() {
        motor_capacity++;
    }

    friend void prelucrareMasina(Masina& m);
};


int Masina::total_masini = 0;


void prelucrareMasina(Masina& m) {
    m.motor_capacity += 0.5;
    m.numar_locuri += 1;
    cout << "Detalii dupa prelucrare:" << endl;
    m.afisareDetalii();
}


int main() {

    Camion c1("Volvo", 20, 2, 12.5, 2020);
    Camion c2("Mercedes", 15, 3, 10.0, 2018);
    Motocicleta m1("Yamaha", 600, true, 5.5, 2021);
    Motocicleta m2("Honda", 500, false, 6.0, 2019);
    Masina mas1("BMW", 5, 2.5, false);
    Masina mas2("Tesla", 4, 0, true);


    prelucrareCamion(c1);
    prelucrareMotocicleta(m1);
    prelucrareMasina(mas1);


    cout << "Operator = pentru Camion:" << endl;
    c1 = c2;
    c1.afisareDetalii();

    cout << "Operator + pentru Camion:" << endl;
    Camion c3 = c1 + c2;
    c3.afisareDetalii();

    cout << "Operator == pentru Camion:" << endl;
    cout << (c1 == c2 ? "Camioanele sunt identice" : "Camioanele nu sunt identice") << endl;

    cout << "Operator ++ pentru Camion (preincrementare):" << endl;
    ++c1;
    c1.afisareDetalii();


    cout << "Operator = pentru Motocicleta:" << endl;
    m1 = m2;
    m1.afisareDetalii();

    cout << "Operator + pentru Motocicleta:" << endl;
    Motocicleta m3 = m1 + m2;
    m3.afisareDetalii();

    cout << "Operator == pentru Motocicleta:" << endl;
    cout << (m1 == m2 ? "Motocicletele sunt identice" : "Motocicletele nu sunt identice") << endl;

    cout << "Operator ++ pentru Motocicleta (preincrementare):" << endl;
    ++m1;
    m1.afisareDetalii();


    cout << "Operator = pentru Masina:" << endl;
    mas1 = mas2;
    mas1.afisareDetalii();

    cout << "Operator + pentru Masina:" << endl;
    Masina mas3 = mas1 + mas2;
    mas3.afisareDetalii();

    cout << "Operator == pentru Masina:" << endl;
    cout << (mas1 == mas2 ? "Masinile sunt identice" : "Masinile nu sunt identice") << endl;

    cout << "Operator ++ pentru Masina (preincrementare):" << endl;
    ++mas1;
    mas1.afisareDetalii();


    Camion::afisareTotalCamioane();
    Motocicleta::afisareTotalMotociclete();
    Masina::afisareTotalMasini();

    return 0;
}