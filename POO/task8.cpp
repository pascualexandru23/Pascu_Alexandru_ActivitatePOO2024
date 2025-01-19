#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Camion {
private:
    string marca;
    int capacitate_tone;
    int* numar_remorci;
    float consum_combustibil;
    int an_fabricatie;

public:
    Camion() {
        marca = "Necunoscut";
        capacitate_tone = 0;
        numar_remorci = new int(0);
        consum_combustibil = 0.0;
        an_fabricatie = 0;
    }

    Camion(string marca, int capacitate, int remorci, float consum, int an) {
        this->marca = marca;
        this->capacitate_tone = capacitate;
        this->numar_remorci = new int(remorci);
        this->consum_combustibil = consum;
        this->an_fabricatie = an;
    }

    ~Camion() {
        delete numar_remorci;
    }

    friend ostream& operator<<(ostream& out, const Camion& c) {
        out << c.marca << " " << c.capacitate_tone << " " << *c.numar_remorci << " "
            << c.consum_combustibil << " " << c.an_fabricatie;
        return out;
    }

    friend istream& operator>>(istream& in, Camion& c) {
        in >> c.marca >> c.capacitate_tone >> *c.numar_remorci >> c.consum_combustibil >> c.an_fabricatie;
        return in;
    }

    void salvareFisierText(const string& fisier) const {
        ofstream fout(fisier, ios::app);
        if (fout.is_open()) {
            fout << marca << "\n" << capacitate_tone << "\n" << *numar_remorci << "\n"
                << consum_combustibil << "\n" << an_fabricatie << "\n";
            fout.close();
        }
    }

    void incarcaDinFisierText(const string& fisier) {
        ifstream fin(fisier);
        if (fin.is_open()) {
            fin >> marca >> capacitate_tone;
            fin >> *numar_remorci >> consum_combustibil >> an_fabricatie;
            fin.close();
        }
    }

    void salvareFisierBinar(const string& fisier) const {
        ofstream fout(fisier, ios::binary | ios::app);
        if (fout.is_open()) {
            size_t len = marca.size();
            fout.write((char*)&len, sizeof(len));
            fout.write(marca.c_str(), len);
            fout.write((char*)&capacitate_tone, sizeof(capacitate_tone));
            fout.write((char*)numar_remorci, sizeof(*numar_remorci));
            fout.write((char*)&consum_combustibil, sizeof(consum_combustibil));
            fout.write((char*)&an_fabricatie, sizeof(an_fabricatie));
            fout.close();
        }
    }

    void incarcaDinFisierBinar(const string& fisier) {
        ifstream fin(fisier, ios::binary);
        if (fin.is_open()) {
            size_t len;
            fin.read((char*)&len, sizeof(len));
            char* buffer = new char[len + 1];
            fin.read(buffer, len);
            buffer[len] = '\0';
            marca = buffer;
            delete[] buffer;

            fin.read((char*)&capacitate_tone, sizeof(capacitate_tone));
            fin.read((char*)numar_remorci, sizeof(*numar_remorci));
            fin.read((char*)&consum_combustibil, sizeof(consum_combustibil));
            fin.read((char*)&an_fabricatie, sizeof(an_fabricatie));
            fin.close();
        }
    }
};

class Flota {
private:
    vector<Camion> flota_camioane;
    string denumire;

public:
    Flota(string denumire = "") : denumire(denumire) {}

    void adaugaCamion(const Camion& camion) {
        flota_camioane.push_back(camion);
    }

    void salvareFisierText(const string& fisier) const {
        ofstream fout(fisier);
        if (fout.is_open()) {
            fout << denumire << "\n" << flota_camioane.size() << "\n";
            for (const auto& camion : flota_camioane) {
                camion.salvareFisierText(fisier);
            }
            fout.close();
        }
    }

    void incarcaDinFisierText(const string& fisier) {
        ifstream fin(fisier);
        if (fin.is_open()) {
            getline(fin, denumire);
            size_t nrCamioane;
            fin >> nrCamioane;
            flota_camioane.clear();
            for (size_t i = 0; i < nrCamioane; ++i) {
                Camion camion;
                camion.incarcaDinFisierText(fisier);
                flota_camioane.push_back(camion);
            }
            fin.close();
        }
    }

    void salvareFisierBinar(const string& fisier) const {
        ofstream fout(fisier, ios::binary);
        if (fout.is_open()) {
            size_t len = denumire.size();
            fout.write((char*)&len, sizeof(len));
            fout.write(denumire.c_str(), len);
            size_t nrCamioane = flota_camioane.size();
            fout.write((char*)&nrCamioane, sizeof(nrCamioane));
            for (const auto& camion : flota_camioane) {
                camion.salvareFisierBinar(fisier);
            }
            fout.close();
        }
    }

    void incarcaDinFisierBinar(const string& fisier) {
        ifstream fin(fisier, ios::binary);
        if (fin.is_open()) {
            size_t len;
            fin.read((char*)&len, sizeof(len));
            char* buffer = new char[len + 1];
            fin.read(buffer, len);
            buffer[len] = '\0';
            denumire = buffer;
            delete[] buffer;

            size_t nrCamioane;
            fin.read((char*)&nrCamioane, sizeof(nrCamioane));
            flota_camioane.clear();
            for (size_t i = 0; i < nrCamioane; ++i) {
                Camion camion;
                camion.incarcaDinFisierBinar(fisier);
                flota_camioane.push_back(camion);
            }
            fin.close();
        }
    }
};

int main() {
    Camion camion1("Mercedes", 10, 2, 25.5, 2020);
    Camion camion2("Volvo", 15, 1, 20.0, 2018);

    camion1.salvareFisierText("camion.txt");
    camion2.salvareFisierBinar("camion.bin");

    Flota flota("Compania X");
    flota.adaugaCamion(camion1);
    flota.adaugaCamion(camion2);

    flota.salvareFisierText("flota.txt");
    flota.salvareFisierBinar("flota.bin");

    return 0;
}