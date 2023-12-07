#include<iostream>
#include"../headers/Character.h"

    Character::~Character()=default;
    Character::Character(const std::string& local_name, const int& local_state) {
        this->name = local_name;
        this->state = local_state;
    }

    [[nodiscard]] std::string Character::getname() const {
        return this->name;
    }
    void Character::setname(const std::string &local_name) {
        this->name = local_name;
    }

    [[nodiscard]] int Character::getstate() const {
        return this->state;
    }
    void Character::setstate(const int &local_state) {
        this->state = local_state;
    }

    std::istream  &operator>>(std::istream &in, Character &c) {
        std::cout << "Caracter: " ;
        in >> c.name;
        std::cout << "Status: ";
        in >> c.state;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Character &c) {
        out << "Caracter: " << c.name << std::endl;
        out << "Status: " << c.state << std::endl;
        return out;
    }