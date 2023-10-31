#include <iostream>
#include <string>

using namespace std;

class Caracter {
private:
    string nume;
    int movement;

public:
    ~Caracter(){cout<<"A fost apelat \n";}
    explicit Caracter(const string& name = "Fork", const int& move = 1) {
        this->nume = name;
        this->movement = move;
    }

    [[nodiscard]] string getnume() const {
        return this->nume;
    }

    void setnume(const string &name) {
        this->nume = name;
    }

    [[nodiscard]] int getmovement() const {
        return this->movement;
    }

    void setmovement(const int &move) {
        this->movement = move;
    }

    friend ostream &operator<<(ostream &out, const Caracter &c);
    friend istream &operator>>(istream &in, Caracter &c);
};

istream  &operator>>(istream &in, Caracter &c) {
    cout << "Caracterul este: " ;
    in >> c.nume;
    cout << "Caracterul are movement-ul: ";
    in >> c.movement;
    return in;
}
ostream &operator<<(ostream &out, const Caracter &c) {
    out << "Caracterul este: " << c.nume << endl;
    out << "Caracterul are movement-ul: " << c.movement << endl;
    return out;
}

class Obstacol {
private:
    int lungime;
    int latime;

public:
    ~Obstacol() { cout << "A fost apelat" << endl; }
    explicit Obstacol(const int& lung = 1 , const int& lat = 1) {
        this->lungime = lung;
        this->latime = lat;
    }

    [[nodiscard]] int getlungime() const {
        return this->lungime;
    }

    void setlungime(int lung) {
        this->lungime = lung;
    }

    [[nodiscard]] int getlatime() const {
        return this->latime;
    }

    void setlatime(int lat) {
        this->latime = lat;
    }

    friend ostream &operator<<(ostream &out, const Obstacol &obs);
    friend istream &operator>>(istream &in, Obstacol &obs);
};

ostream &operator<<(ostream &out, const Obstacol &obs) {
    out << "Lungimea obstacolului este: " << obs.latime << endl;
    out << "Latimea obstacolului este: " << obs.lungime << endl;
    return out;
}
istream  &operator>>(istream &in, Obstacol &obs) {
    cout << "Lungimea obstacolului este: " ;
    in >> obs.lungime;
    cout << "Latimea obstacolului este: ";
    in >> obs.latime;
    return in;
}

class Scoreboard {
private:
    string nume;
    int score;

public:
    ~Scoreboard(){cout<<"A fost apelat \n";}
    explicit Scoreboard(const string& name = "Player1", const int& scor = 0) {
        this->nume = name;
        this->score = scor;
    }

    [[nodiscard]] string getnume() const {
        return this->nume;
    }

    void setnume(const string &name) {
        this->nume = name;
    }

    [[nodiscard]] int getscore() const {
        return this->score;
    }

    void setscore(const int &scor) {
        this->score = scor;
    }

    friend ostream &operator<<(ostream &out, const Scoreboard &sb);
    friend istream &operator>>(istream &in, Scoreboard &sb);
};

istream  &operator>>(istream &in, Scoreboard &sb) {
    cout << "Nume: " ;
    in >> sb.nume;
    cout << "Score: ";
    in >> sb.score;
    return in;
}
ostream &operator<<(ostream &out, const Scoreboard &sb) {
    out << "Nume: " << sb.nume << endl;
    out << "Score: " << sb.score << endl;
    return out;
}

int main() {

    Caracter c1("Fork", 1);
    cout << c1;
    Caracter c2;
    c2.setnume("Knife");
    c2.setmovement(2);
    cout << "Caracterul este : " << c2.getnume() << " \n";
    cout << "Caracterul are movement-ul: " << c2.getmovement() << " \n";

    Obstacol obs1(1,1);
    cout << obs1;
    Obstacol obs2;
    obs2.setlungime(3);
    obs2.setlatime(4);
    cout << "Lungimea obstacolului este : " << obs2.getlungime()<< "\n";
    cout << "Latimea obstacolului este: " << obs2.getlatime()<<"\n";

    Scoreboard sb1("Max", 30);
    cout << sb1;
    Scoreboard sb2;
    sb2.setnume("Alex");
    sb2.setscore(2);
    cout << "Nume: " << sb2.getnume() << " \n";
    cout << "Score: " << sb2.getscore() << " \n";

    return 0;
}