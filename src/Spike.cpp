#include<iostream>
#include"../headers/Spike.h"

    Spike::~Spike()=default;
    Spike::Spike(const int& local_length, const int& local_points, const int& local_direction) {
        this->length = local_length;
        this->points = local_points;
        this->direction = local_direction;
    }

    [[nodiscard]] int Spike::getdirection() const {
        return this->direction;
    }
    void Spike::setdirection(int local_direction) {
        this->direction = local_direction;
    }

    void Spike::citirespike(){
        Obstacle::citire();
        std::cout<<"Directie:";
        std::cin>> direction;
    }

    void Spike::afisarespike(){
        Obstacle::afisare();
        std::cout << "Directie: " << direction << "\n";
    }

    int Spike::directionstate(int local_state){
        if (local_state == 1 || local_state == 2)
            return this->direction = local_state;
        return this->direction = 0;
    }

    std::ostream &operator<<(std::ostream &out, const Spike &h) {
        out << "Directie: " << h.direction << std::endl;
        return out;
    }

    std::istream  &operator>>(std::istream &in, Spike &h) {
        std::cout << "Directie: " ;
        in >> h.direction;
        return in;
    }