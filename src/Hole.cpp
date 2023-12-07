#include<iostream>
#include"../headers/Hole.h"

    Hole::~Hole()=default;
    Hole::Hole(const int& local_length, const int& local_points, const int& local_depth) {
        this->length = local_length;
        this->points = local_points;
        this->depth = local_depth;
    }

    [[nodiscard]] int Hole::getdepth() const {
        return this->depth;
    }
    void Hole::setdepth(int local_depth) {
        this->depth = local_depth;
    }

    void Hole::citirehole(){
        Obstacle::citire();
        std::cout<<"Adancime:";
        std::cin>> depth;
    }

    void Hole::afisarehole(){
        Obstacle::afisare();
        std::cout << "Adancime: " << depth << "\n";
    }

    std::ostream &operator<<(std::ostream &out, const Hole &h) {
        out << "Adancime: " << h.depth << std::endl;
        return out;

    }

    std::istream  &operator>>(std::istream &in, Hole &h) {
        std::cout << "Adancime: " ;
        in >> h.depth;
        return in;
    }