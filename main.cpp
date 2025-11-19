#include <iostream>
#include <string>
using namespace std;

class Copac {
private:
    string nume;
    static int nrCopaci;
    const int id;
    int* inaltime;

public:
    Copac() : id(1) {
        nume = "Tei";
        inaltime = new int(300);
        nrCopaci++;
    }

    Copac(string numeCopac) : id(2) {
        nume = numeCopac;
        inaltime = new int(250);
        nrCopaci++;
    }

    Copac(string numeCopac, int idCopac, int inaltimeCopac) : id(idCopac) {
        nume = numeCopac;
        inaltime = new int(inaltimeCopac);
        nrCopaci++;
    }

    Copac(const Copac& c) : id(c.id) {
        nume = c.nume;
        inaltime = new int(*c.inaltime);
        nrCopaci++;
    }

    ~Copac() {
        delete inaltime;
        nrCopaci--;
    }

    void afisare() {
        cout << "Copac: " << nume << ", id = " << id << ", inaltime = " << *inaltime << " cm\n";
    }

    static void infoStatica() {
        cout << "In parc sunt " << nrCopaci << " copaci (construiti momentan).\n";
    }

    string getNume() const { return nume; }
    int getId() const { return id; }
    int getInaltime() const { return *inaltime; }
    static int getNrCopaci() { return nrCopaci; }

    void setNume(const string& n) { nume = n; }
    void setInaltime(int h) { *inaltime = h; }
    static void setNrCopaci(int v) { nrCopaci = v; }

    friend void comparaCopaci(const Copac& c1, const Copac& c2);
};

int Copac::nrCopaci = 0;

class Banca {
private:
    string material;
    static int nrBanci;
    const int id;
    int* nrLocuri;

public:
    Banca() : id(1) {
        material = "Lemn";
        nrLocuri = new int(3);
        nrBanci++;
    }

    Banca(string mat) : id(2) {
        material = mat;
        nrLocuri = new int(4);
        nrBanci++;
    }

    Banca(string mat, int idBanca, int locuri) : id(idBanca) {
        material = mat;
        nrLocuri = new int(locuri);
        nrBanci++;
    }

    Banca(const Banca& b) : id(b.id) {
        material = b.material;
        nrLocuri = new int(*b.nrLocuri);
        nrBanci++;
    }

    ~Banca() {
        delete nrLocuri;
        nrBanci--;
    }

    void afisare() {
        cout << "Banca: " << material << ", id = " << id << ", locuri = " << *nrLocuri << "\n";
    }

    static void infoStatica() {
        cout << "In parc sunt " << nrBanci << " banci (construite momentan).\n";
    }

    string getMaterial() const { return material; }
    int getId() const { return id; }
    int getNrLocuri() const { return *nrLocuri; }
    static int getNrBanci() { return nrBanci; }

    void setMaterial(const string& m) { material = m; }
    void setNrLocuri(int l) { *nrLocuri = l; }
    static void setNrBanci(int v) { nrBanci = v; }
};

int Banca::nrBanci = 0;

class Alee {
private:
    string nume;
    static int nrAlei;
    const int id;
    int* lungime;

public:
    Alee() : id(1) {
        nume = "Aleea Centrala";
        lungime = new int(100);
        nrAlei++;
    }

    Alee(string numeAlee) : id(2) {
        nume = numeAlee;
        lungime = new int(80);
        nrAlei++;
    }

    Alee(string numeAlee, int idAlee, int lungimeAlee) : id(idAlee) {
        nume = numeAlee;
        lungime = new int(lungimeAlee);
        nrAlei++;
    }

    Alee(const Alee& a) : id(a.id) {
        nume = a.nume;
        lungime = new int(*a.lungime);
        nrAlei++;
    }

    ~Alee() {
        delete lungime;
        nrAlei--;
    }

    void afisare() {
        cout << "Alee: " << nume << ", id = " << id << ", lungime = " << *lungime << " m\n";
    }

    static void infoStatica() {
        cout << "In parc sunt " << nrAlei << " alei (construite momentan).\n";
    }

    string getNume() const { return nume; }
    int getId() const { return id; }
    int getLungime() const { return *lungime; }
    static int getNrAlei() { return nrAlei; }

    void setNume(const string& n) { nume = n; }
    void setLungime(int l) { *lungime = l; }
    static void setNrAlei(int v) { nrAlei = v; }

    friend void lungireAlee(Alee& a, int delta);
};

int Alee::nrAlei = 0;

void comparaCopaci(const Copac& c1, const Copac& c2) {
    if (*c1.inaltime > *c2.inaltime)
        cout << c1.nume << " este mai inalt decat " << c2.nume << ".\n";
    else if (*c1.inaltime < *c2.inaltime)
        cout << c2.nume << " este mai inalt decat " << c1.nume << ".\n";
    else
        cout << "Cei doi copaci au aceeasi inaltime.\n";
}

void lungireAlee(Alee& a, int delta) {
    *a.lungime = *a.lungime + delta;
    cout << "Noua lungime a aleii este " << *a.lungime << " m.\n";
}

int main() {
    cout << "Test parc - Faza 2\n\n";

    Copac c1;
    Copac c2("Stejar");
    Copac c3("Molid", 10, 420);
    Copac c4 = c2;

    c1.afisare();
    c2.afisare();
    c3.afisare();
    c4.afisare();

    c1.setNume("Tei Mare");
    c1.setInaltime(310);

    cout << c1.getNume() << " are inaltimea " << c1.getInaltime() << " cm.\n";
    Copac::infoStatica();

    comparaCopaci(c2, c3);

    Banca b1;
    Banca b2("Metal");
    Banca b3("Plastic", 5, 2);
    Banca b4 = b1;

    b1.afisare();
    b2.afisare();
    b3.afisare();
    b4.afisare();

    b2.setMaterial("Metal Vopsit");
    b2.setNrLocuri(6);

    cout << b2.getMaterial() << " cu " << b2.getNrLocuri() << " locuri.\n";
    Banca::infoStatica();

    Alee a1;
    Alee a2("Aleea Copiilor");
    Alee a3("Aleea Lac", 7, 250);
    Alee a4 = a3;

    a1.afisare();
    a2.afisare();
    a3.afisare();
    a4.afisare();

    a3.setNume("Aleea Lac Mare");
    a3.setLungime(300);

    cout << a3.getNume() << " are lungimea de " << a3.getLungime() << " m.\n";
    Alee::infoStatica();

    lungireAlee(a2, 20);

    return 0;
}
