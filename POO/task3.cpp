#include <iostream>
#include <string>
#include <cstring>
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

    string getMarca() const { return marca; }
    void setMarca(const string& marca) { this->marca = marca; }

    int getCapacitateTone() const { return capacitate_tone; }
    void setCapacitateTone(int capacitate) { capacitate_tone = capacitate; }

    int getNumarRemorci() const { return *numar_remorci; }
    void setNumarRemorci(int remorci) { *numar_remorci = remorci; }

    float getConsumCombustibil() const { return consum_combustibil; }
    void setConsumCombustibil(float consum) { consum_combustibil = consum; }

    int getAnFabricatie() const { return an_fabricatie; }
    void setAnFabricatie(int an) { an_fabricatie = an; }

    static int getTotalCamioane() { return total_camioane; }
    static void setTotalCamioane(int total) { total_camioane = total; }

    friend void prelucrareCamion(Camion& c);
};

int Camion::total_camioane = 0;

class Masina {
private:
    string marca;
    int numar_usi;
    int* viteza_maxima;
    float capacitate_motor;
    int an_fabricatie;
    static int total_masini;
    const string tip_combustibil;

public:
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

    Masina(const Masina& other) : tip_combustibil("Benzina") {
        marca = other.marca;
        numar_usi = other.numar_usi;
        viteza_maxima = new int(*other.viteza_maxima);
        capacitate_motor = other.capacitate_motor;
        an_fabricatie = other.an_fabricatie;
        total_masini++;
    }

    ~Masina() {
        delete viteza_maxima;
    }

    static void afisareTotalMasini() {
        cout << "Total masini: " << total_masini << endl;
    }

    void afisareDetalii() {
        cout << "Masina: " << marca << ", Numar usi: " << numar_usi << ", Viteza maxima: " << *viteza_maxima
            << " km/h, Capacitate motor: " << capacitate_motor << " L, An fabricatie: " << an_fabricatie
            << ", Tip combustibil: " << tip_combustibil << endl;
    }

    string getMarca() const { return marca; }
    void setMarca(const string& marca) { this->marca = marca; }

    int getNumarUsi() const { return numar_usi; }
    void setNumarUsi(int numar_usi) { this->numar_usi = numar_usi; }

    int getVitezaMaxima() const { return *viteza_maxima; }
    void setVitezaMaxima(int viteza) { *viteza_maxima = viteza; }

    float getCapacitateMotor() const { return capacitate_motor; }
    void setCapacitateMotor(float capacitate) { capacitate_motor = capacitate; }

    int getAnFabricatie() const { return an_fabricatie; }
    void setAnFabricatie(int an) { an_fabricatie = an; }

    static int getTotalMasini() { return total_masini; }
    static void setTotalMasini(int total) { total_masini = total; }

    friend void prelucrareMasina(Masina& m);
};

int Masina::total_masini = 0;

class Motocicleta {
private:
    string marca;
    int numar_roti;
    char* tip_motocicleta;
    float capacitate_motor;
    int an_fabricatie;
    static int total_motociclete;
    const string tip_combustibil;

public:
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
        strcpy(this->tip_motocicleta, "Standard");
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

    Motocicleta(const Motocicleta& other) : tip_combustibil("Benzina") {
        marca = other.marca;
        numar_roti = other.numar_roti;
        tip_motocicleta = new char[strlen(other.tip_motocicleta) + 1];
        strcpy(tip_motocicleta, other.tip_motocicleta);
        capacitate_motor = other.capacitate_motor;
        an_fabricatie = other.an_fabricatie;
        total_motociclete++;
    }

    ~Motocicleta() {
        delete[] tip_motocicleta;
    }

    static void afisareTotalMotociclete() {
        cout << "Total motociclete: " << total_motociclete << endl;
    }

    void afisareDetalii() {
        cout << "Motocicleta: " << marca << ", Numar roti: " << numar_roti << ", Tip: " << tip_motocicleta
            << ", Capacitate motor: " << capacitate_motor << " L, An fabricatie: " << an_fabricatie
            << ", Tip combustibil: " << tip_combustibil << endl;
    }

    string getMarca() const { return marca; }
    void setMarca(const string& marca) { this->marca = marca; }

    int getNumarRoti() const { return numar_roti; }
    void setNumarRoti(int roti) { numar_roti = roti; }

    const char* getTipMotocicleta() const { return tip_motocicleta; }
    void setTipMotocicleta(const char* tip) {
        delete[] tip_motocicleta;
        tip_motocicleta = new char[strlen(tip) + 1];
        strcpy(tip_motocicleta, tip);
    }

    float getCapacitateMotor() const { return capacitate_motor; }
    void setCapacitateMotor(float capacitate) { capacitate_motor = capacitate; }

    int getAnFabricatie() const { return an_fabricatie; }
    void setAnFabricatie(int an) { an_fabricatie = an; }

    static int getTotalMotociclete() { return total_motociclete; }
    static void setTotalMotociclete(int total) { total_motociclete = total; }

    friend void prelucrareMotocicleta(Motocicleta& m);
};

int Motocicleta::total_motociclete = 0;

void prelucrareCamion(Camion& c) {
    c.setMarca("Volvo");
    c.setCapacitateTone(25);
    c.setNumarRemorci(2);
    c.setConsumCombustibil(15.0);
    c.setAnFabricatie(2020);
}

void prelucrareMasina(Masina& m) {
    m.setMarca("BMW");
    m.setNumarUsi(5);
    m.setVitezaMaxima(250);
    m.setCapacitateMotor(3.0);
    m.setAnFabricatie(2022);
}

void prelucrareMotocicleta(Motocicleta& m) {
    m.setMarca("Yamaha");
    m.setNumarRoti(2);
    m.setTipMotocicleta("Sport");
    m.setCapacitateMotor(1.0);
    m.setAnFabricatie(2023);
}

int main() {
    Camion c1("Scania", 40, 3, 18.5, 2021);
    Masina m1("Audi", 4, 220, 2.5, 2020);
    Motocicleta moto1("Honda", 2, "Cruiser", 1.2, 2022);

    cout << "Detalii Camion inainte de prelucrare:" << endl;
    cout << "Marca: " << c1.getMarca() << endl;
    cout << "Capacitate tone: " << c1.getCapacitateTone() << endl;
    cout << "Numar remorci: " << c1.getNumarRemorci() << endl;
    cout << "Consum combustibil: " << c1.getConsumCombustibil() << " L/100km" << endl;
    cout << "An fabricatie: " << c1.getAnFabricatie() << endl;
    cout << "Tip combustibil: " << c1.getTotalCamioane() << endl;
    cout << endl;

    cout << "Detalii Masina inainte de prelucrare:" << endl;
    cout << "Marca: " << m1.getMarca() << endl;
    cout << "Numar usi: " << m1.getNumarUsi() << endl;
    cout << "Viteza maxima: " << m1.getVitezaMaxima() << " km/h" << endl;
    cout << "Capacitate motor: " << m1.getCapacitateMotor() << " L" << endl;
    cout << "An fabricatie: " << m1.getAnFabricatie() << endl;
    cout << "Tip combustibil: " << m1.getTotalMasini() << endl;
    cout << endl;

    cout << "Detalii Motocicleta inainte de prelucrare:" << endl;
    cout << "Marca: " << moto1.getMarca() << endl;
    cout << "Numar roti: " << moto1.getNumarRoti() << endl;
    cout << "Tip motocicleta: " << moto1.getTipMotocicleta() << endl;
    cout << "Capacitate motor: " << moto1.getCapacitateMotor() << " L" << endl;
    cout << "An fabricatie: " << moto1.getAnFabricatie() << endl;
    cout << endl;

    prelucrareCamion(c1);
    prelucrareMasina(m1);
    prelucrareMotocicleta(moto1);

    cout << "Detalii Camion dupa prelucrare:" << endl;
    c1.afisareDetalii();
    cout << endl;

    cout << "Detalii Masina dupa prelucrare:" << endl;
    m1.afisareDetalii();
    cout << endl;

    cout << "Detalii Motocicleta dupa prelucrare:" << endl;
    moto1.afisareDetalii();
    cout << endl;

    Camion::afisareTotalCamioane();
    Masina::afisareTotalMasini();
    Motocicleta::afisareTotalMotociclete();

    return 0;
}