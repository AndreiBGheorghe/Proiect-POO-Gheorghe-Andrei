#include<iostream>
#include"../headers/Obstacle.h"

    Obstacle::~Obstacle()=default;
    Obstacle::Obstacle(const int& local_length, const int& local_points) {
        this->length = local_length;
        this->points = local_points;
    }

    [[nodiscard]] int Obstacle::getlength() const {
        return this->length;
    }
    void Obstacle::setlength(int local_length) {
        this->length = local_length;
    }

    [[nodiscard]] int Obstacle::getpoints() const {
        return this->points;
    }
    void Obstacle::setpoints(int local_points) {
        this->points = local_points;
    }

    void Obstacle::citire(){
        std::cout<<"Lungime:";
        std::cin>> length;
        std::cout<<"Puncte:";
        std::cin>> points;
    }
    void Obstacle::afisare(){
        std::cout << "Lungime: " << length << "\n";
        std::cout << "Puncte: " << points <<"\n";
    }

    std::ostream &operator<<(std::ostream &out, const Obstacle &obs) {
        out << "Lungime: " << obs.length << std::endl;
        out << "Puncte: " << obs.points << std::endl;
        return out;
    }

    std::istream  &operator>>(std::istream &in, Obstacle &obs) {
        std::cout << "Lungime: " ;
        in >> obs.length;
        std::cout << "Puncte: ";
        in >> obs.points;
        return in;
    }