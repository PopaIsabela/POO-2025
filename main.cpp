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

    Copac& operator=(const Copac& c) {
        if (this != &c) {
            nume = c.nume;
            if (inaltime != nullptr) {
                delete inaltime;
            }
            inaltime = new int(*c.inaltime);
        }
        return *this;
    }

    ~Copac() {
        delete inaltime;
        nrCopaci--;
    }

    void afisare() {
        cout << "Copac: " << nume << ", id = " << id << ", inaltime = " << *inaltime << " cm\n";
    }

    void descriere() {
        cout << "Descriere copac: " << nume << " are inaltimea de " << *inaltime << " cm\n";
    }

    static void infoStatica() {
        cout << "In parc sunt " << nrCopaci << " copaci.\n";
    }

    string getNume() const { return nume; }
    int getId() const { return id; }
    int getInaltime() const { return *inaltime; }
    static int getNrCopaci() { return nrCopaci; }

    void setNume(const string& n) { nume = n; }
    void setInaltime(int h) { *inaltime = h; }
    static void setNrCopaci(int v) { nrCopaci = v; }

    bool operator==(const Copac& c) const {
        return nume == c.nume && *inaltime == *c.inaltime;
    }

    bool operator<(const Copac& c) const {
        return *inaltime < *c.inaltime;
    }

    Copac operator+(int delta) const {
        Copac rez(nume, id, *inaltime + delta);
        return rez;
    }

    Copac& operator+=(int delta) {
        *inaltime = *inaltime + delta;
        return *this;
    }

    void citire() {
        string n;
        int h;
        cout << "Nume copac: ";
        cin >> n;
        cout << "Inaltime copac: ";
        cin >> h;
        setNume(n);
        setInaltime(h);
    }

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

    Banca& operator=(const Banca& b) {
        if (this != &b) {
            material = b.material;
            if (nrLocuri != nullptr) {
                delete nrLocuri;
            }
            nrLocuri = new int(*b.nrLocuri);
        }
        return *this;
    }

    ~Banca() {
        delete nrLocuri;
        nrBanci--;
    }

    void afisare() {
        cout << "Banca: " << material << ", id = " << id << ", locuri = " << *nrLocuri << "\n";
    }

    void infoMaterial() {
        cout << "Material banca: " << material << "\n";
    }

    static void infoStatica() {
        cout << "In parc sunt " << nrBanci << " banci.\n";
    }

    string getMaterial() const { return material; }
    int getId() const { return id; }
    int getNrLocuri() const { return *nrLocuri; }
    static int getNrBanci() { return nrBanci; }

    void setMaterial(const string& m) { material = m; }
    void setNrLocuri(int l) { *nrLocuri = l; }
    static void setNrBanci(int v) { nrBanci = v; }

    bool operator==(const Banca& b) const {
        return material == b.material && *nrLocuri == *b.nrLocuri;
    }

    bool operator<(const Banca& b) const {
        return *nrLocuri < *b.nrLocuri;
    }

    Banca operator+(int deltaLocuri) const {
        Banca rez(material, id, *nrLocuri + deltaLocuri);
        return rez;
    }

    Banca& operator+=(int deltaLocuri) {
        *nrLocuri = *nrLocuri + deltaLocuri;
        return *this;
    }

    void citire() {
        string m;
        int l;
        cout << "Material banca: ";
        cin >> m;
        cout << "Numar locuri: ";
        cin >> l;
        setMaterial(m);
        setNrLocuri(l);
    }
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

    Alee& operator=(const Alee& a) {
        if (this != &a) {
            nume = a.nume;
            if (lungime != nullptr) {
                delete lungime;
            }
            lungime = new int(*a.lungime);
        }
        return *this;
    }

    ~Alee() {
        delete lungime;
        nrAlei--;
    }

    void afisare() {
        cout << "Alee: " << nume << ", id = " << id << ", lungime = " << *lungime << " m\n";
    }

    void infoLungime() {
        cout << "Lungimea aleii: " << *lungime << " m\n";
    }

    static void infoStatica() {
        cout << "In parc sunt " << nrAlei << " alei.\n";
    }

    string getNume() const { return nume; }
    int getId() const { return id; }
    int getLungime() const { return *lungime; }
    static int getNrAlei() { return nrAlei; }

    void setNume(const string& n) { nume = n; }
    void setLungime(int l) { *lungime = l; }
    static void setNrAlei(int v) { nrAlei = v; }

    bool operator==(const Alee& a) const {
        return nume == a.nume && *lungime == *a.lungime;
    }

    bool operator<(const Alee& a) const {
        return *lungime < *a.lungime;
    }

    Alee operator+(int delta) const {
        Alee rez(nume, id, *lungime + delta);
        return rez;
    }

    Alee& operator+=(int delta) {
        *lungime = *lungime + delta;
        return *this;
    }

    void citire() {
        string n;
        int l;
        cout << "Nume alee: ";
        cin >> n;
        cout << "Lungime alee: ";
        cin >> l;
        setNume(n);
        setLungime(l);
    }

    friend void lungireAlee(Alee& a, int delta);
};

int Alee::nrAlei = 0;

class ZonaParc {
private:
    string numeZona;
    Copac copacPrincipal;
    int nrBanciZona;
    int nrAleiZona;

public:
    ZonaParc() : copacPrincipal() {
        numeZona = "Zona standard";
        nrBanciZona = 0;
        nrAleiZona = 0;
    }

    ZonaParc(string nume, const Copac& c, int nrBanci, int nrAlei) : copacPrincipal(c) {
        numeZona = nume;
        nrBanciZona = nrBanci;
        nrAleiZona = nrAlei;
    }

    ZonaParc(const ZonaParc& z) : copacPrincipal(z.copacPrincipal) {
        numeZona = z.numeZona;
        nrBanciZona = z.nrBanciZona;
        nrAleiZona = z.nrAleiZona;
    }

    ZonaParc& operator=(const ZonaParc& z) {
        if (this != &z) {
            numeZona = z.numeZona;
            copacPrincipal = z.copacPrincipal;
            nrBanciZona = z.nrBanciZona;
            nrAleiZona = z.nrAleiZona;
        }
        return *this;
    }

    string getNumeZona() const { return numeZona; }
    Copac getCopacPrincipal() const { return copacPrincipal; }
    int getNrBanciZona() const { return nrBanciZona; }
    int getNrAleiZona() const { return nrAleiZona; }

    void setNumeZona(const string& n) { numeZona = n; }
    void setCopacPrincipal(const Copac& c) { copacPrincipal = c; }
    void setNrBanciZona(int x) { nrBanciZona = x; }
    void setNrAleiZona(int x) { nrAleiZona = x; }

    bool operator==(const ZonaParc& z) const {
        return numeZona == z.numeZona &&
               nrBanciZona == z.nrBanciZona &&
               nrAleiZona == z.nrAleiZona &&
               copacPrincipal.getNume() == z.copacPrincipal.getNume();
    }

    bool operator<(const ZonaParc& z) const {
        int totalThis = nrBanciZona + nrAleiZona;
        int totalAlt = z.nrBanciZona + z.nrAleiZona;
        return totalThis < totalAlt;
    }

    ZonaParc& operator+=(int deltaBanci) {
        nrBanciZona = nrBanciZona + deltaBanci;
        return *this;
    }

    void afisareZona() {
        cout << "Zona parc: " << numeZona
             << ", banci: " << nrBanciZona
             << ", alei: " << nrAleiZona
             << ", copac principal: ";
        copacPrincipal.afisare();
    }
};

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
    cout << "Test parc\n\n";

    Copac c1;
    Copac c2("Stejar");
    Copac c3("Molid", 10, 420);
    Copac c4 = c2;

    c1.afisare();
    c2.afisare();
    c3.afisare();
    c4.afisare();

    c1.descriere();

    if (c2 == c4) cout << "c2 si c4 sunt egali\n";
    if (c2 < c3) cout << "c2 este mai scund decat c3\n";

    Copac c5 = c2 + 30;
    c5.afisare();

    c2 += 15;
    c2.afisare();

    Copac c6("Brad", 12, 350);
    c6 = c3;
    c6.afisare();

    comparaCopaci(c2, c3);

    cout << "\nBanci:\n";
    Banca b1;
    Banca b2("Metal");
    Banca b3("Plastic", 5, 2);
    Banca b4 = b1;

    b1.afisare();
    b2.afisare();
    b3.afisare();
    b4.afisare();

    b1.infoMaterial();

    if (b1 == b4) cout << "b1 si b4 sunt egale\n";
    if (b3 < b2) cout << "b3 are mai putine locuri decat b2\n";

    Banca b5 = b2 + 3;
    b5.afisare();

    b3 += 2;
    b3.afisare();

    b4 = b3;
    b4.afisare();

    cout << "\nAlei:\n";
    Alee a1;
    Alee a2("Aleea Copiilor");
    Alee a3("Aleea Lac", 7, 250);
    Alee a4 = a3;

    a1.afisare();
    a2.afisare();
    a3.afisare();
    a4.afisare();

    a1.infoLungime();

    if (a3 == a4) cout << "a3 si a4 sunt egale\n";
    if (a2 < a3) cout << "a2 este mai scurta decat a3\n";

    Alee a5 = a2 + 40;
    a5.afisare();

    a2 += 10;
    a2.afisare();

    a4 = a1;
    a4.afisare();

    lungireAlee(a2, 20);

    const int NR_COPACI_V = 2;
    const int NR_BANCI_V = 2;
    const int NR_ALEI_V = 2;

    Copac vectorCopaci[NR_COPACI_V];
    Banca vectorBanci[NR_BANCI_V];
    Alee vectorAlei[NR_ALEI_V];

    cout << "\nVector copaci (citire):\n";
    for (int i = 0; i < NR_COPACI_V; i++) {
        cout << "Copac " << i + 1 << ":\n";
        vectorCopaci[i].citire();
    }

    cout << "\nVector copaci (afisare):\n";
    for (int i = 0; i < NR_COPACI_V; i++) {
        vectorCopaci[i].afisare();
    }

    cout << "\nVector banci (citire):\n";
    for (int i = 0; i < NR_BANCI_V; i++) {
        cout << "Banca " << i + 1 << ":\n";
        vectorBanci[i].citire();
    }

    cout << "\nVector banci (afisare):\n";
    for (int i = 0; i < NR_BANCI_V; i++) {
        vectorBanci[i].afisare();
    }

    cout << "\nVector alei (citire):\n";
    for (int i = 0; i < NR_ALEI_V; i++) {
        cout << "Alee " << i + 1 << ":\n";
        vectorAlei[i].citire();
    }

    cout << "\nVector alei (afisare):\n";
    for (int i = 0; i < NR_ALEI_V; i++) {
        vectorAlei[i].afisare();
    }

    const int LINII = 2;
    const int COLOANE = 2;
    Alee matriceAlei[LINII][COLOANE];

    cout << "\nMatrice de alei (citire):\n";
    for (int i = 0; i < LINII; i++) {
        for (int j = 0; j < COLOANE; j++) {
            cout << "Alee [" << i << "][" << j << "]:\n";
            matriceAlei[i][j].citire();
        }
    }

    cout << "\nMatrice de alei (afisare):\n";
    for (int i = 0; i < LINII; i++) {
        for (int j = 0; j < COLOANE; j++) {
            matriceAlei[i][j].afisare();
        }
    }

    cout << "\nZone parc:\n";
    ZonaParc z1;
    ZonaParc z2("Zona Copaci Mari", c3, 3, 2);
    ZonaParc z3("Zona mica", c1, 1, 1);

    z1.afisareZona();
    z2.afisareZona();
    z3.afisareZona();

    if (z1 < z2) cout << "z1 are mai putine obiecte decat z2\n";
    if (z3 < z2) cout << "z3 are mai putine obiecte decat z2\n";

    z1 = z2;
    z1.afisareZona();

    if (z1 == z2) cout << "z1 si z2 sunt egale ca zona\n";

    z2 += 2;
    z2.afisareZona();

    cout << "\nSfarsit test.\n";
    return 0;
}
