#include<iostream>
#include<string>
#include"../headers/Scoreboard.h"

    Scoreboard::~Scoreboard()=default;
    Scoreboard::Scoreboard(const std::string& local_name, const int& local_score) {
        this->name = local_name;
        this->score = local_score;
    }

    [[nodiscard]] std::string Scoreboard::getname() const {
        return this->name;
    }
    void Scoreboard::setname(const std::string &local_name) {
        this->name = local_name;
    }

    [[nodiscard]] int Scoreboard::getscore() const {
        return this->score;
    }
    void Scoreboard::setscore(const int &local_score) {
        this->score = local_score;
    }

    bool Scoreboard::valid_name(const std::string &local_name){
        if (local_name.length() <= 3){
            std::cout<<"Este valid"<<"\n";
            return true;
        }
        std::cout<<"Nu este valid"<<"\n\n";
        return false;
    }

    std::istream  &operator>>(std::istream &in, Scoreboard &sb) {
        std::cout << "Nume: " ;
        in >> sb.name;
        std::cout << "Scor: ";
        in >> sb.score;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Scoreboard &sb) {
        out << "Nume: " << sb.name << std::endl;
        out << "Score: " << sb.score << std::endl;
        return out;
    }