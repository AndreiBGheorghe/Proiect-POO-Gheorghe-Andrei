#include <iostream>
#include <string>
#include "headers/Character.h"
#include "headers/Obstacle.h"
#include "headers/Scoreboard.h"
#include "headers/Hole.h"
#include "headers/Spike.h"
#include "headers/Normal.h"
#include "headers/NegativeNr.h"
#include <memory>
#include <vector>

std::vector<std::shared_ptr<Obstacle>> ob;
std::shared_ptr<Hole> h = std::make_shared<Hole>(2,2,2);
std::shared_ptr<Spike> sp = std::make_shared<Spike>();
std::shared_ptr<Normal> nm = std::make_shared<Normal>();

int main() {

    Character c1("Fork", 1);
    std::cout << c1;
    Character c2;
    c2.setname("Knife");
    c2.setstate(2);
    std::cout << "Caracter: " << c2.getname() << " \n";
    std::cout << "Status: " << c2.getstate() << " \n\n";

    Obstacle obs1(1,1);
    std::cout << obs1;
    Obstacle obs2;
    obs2.setlength(3);
    obs2.setpoints(4);
    std::cout << "Lungime: " << obs2.getlength()<< "\n";
    std::cout << "Puncte: " << obs2.getpoints()<<"\n\n";

    /*Obstacle* clona = obs2.clone();
    std::cout << clona;*/

    Scoreboard sb1("Max", 30);
    std::cout << sb1;
    Scoreboard::valid_name(sb1.getname());
    Scoreboard sb2;
    sb2.setname("Alex");
    sb2.setscore(2);
    std::cout << "Nume: " << sb2.getname() << " \n";
    std::cout << "Score: " << sb2.getscore() << " \n";
    Scoreboard::valid_name(sb2.getname());


    Hole h1;
    h1.citirehole();
    h1.afisarehole();

    Spike sp1;
    sp1.citirespike();
    sp1.afisarespike();
    sp1.directionstate(c1.getstate());
    sp1.afisarespike();

    Normal n1;
    n1.citirenormal();
    try {
        if (n1.getheight() < 0) {
            throw NegativeNr();
        }
        std::cout << "Numarul introdus este: " << n1.getheight() << std::endl;
    } catch (const NegativeNr& e) {
        std::cerr << "Exceptie: " << e.what() << std::endl;
    }

    ob.push_back(h);
    ob.push_back(sp);
    ob.push_back(nm);

    return 0;
}