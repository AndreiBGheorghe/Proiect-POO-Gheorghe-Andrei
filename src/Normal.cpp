#include<iostream>
#include"../headers/Normal.h"

    Normal::~Normal()=default;
    Normal::Normal(const int& local_length, const int& local_points, const int& local_height) {
        this->length = local_length;
        this->points = local_points;
        this->height = local_height;
    }

    [[nodiscard]] int Normal::getheight() const {
        return this->height;
    }
    void Normal::setheight(int local_height) {
        this->height = local_height;
    }

    void Normal::citirenormal(){
        Obstacle::citire();
        std::cout<<"Inaltime:";
        std::cin>> height;
    }

    void Normal::afisarenormal(){
        Obstacle::afisare();
        std::cout << "Inaltime: " << height << "\n";
    }

    std::ostream &operator<<(std::ostream &out, const Normal &h) {
        out << "Inaltime: " << h.height << std::endl;
        return out;
    }

    std::istream  &operator>>(std::istream &in, Normal &h) {
        std::cout << "Inaltime: " ;
        in >> h.height;
        return in;
    }