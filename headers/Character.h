#ifndef OOP_CHARACTER_H
#define OOP_CHARACTER_H

#include <string>

class Character {
private:
    std::string name;
    int state;

public:
    ~Character();
    explicit Character(const std::string& local_name = "Fork", const int& local_state = 1);

    [[nodiscard]] std::string getname() const;
    void setname(const std::string &local_name);

    [[nodiscard]] int getstate() const;
    void setstate(const int &local_state);

    friend std::ostream &operator<<(std::ostream &out, const Character &c);
    friend std::istream &operator>>(std::istream &in, Character &c);
};

#endif