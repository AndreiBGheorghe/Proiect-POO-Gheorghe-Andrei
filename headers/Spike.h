#ifndef OOP_SPIKE_H
#define OOP_SPIKE_H

#include"../headers/Obstacle.h"
#include"../headers/Character.h"

class Spike : public Obstacle {
protected:
    int direction;

public:
    ~Spike();
    explicit Spike(const int& local_length = 1, const int& local_points = 1, const int& local_direction = 1);

    [[nodiscard]] int getdirection() const;
    void setdirection(int local_direction);

    void citirespike();
    void afisarespike();
    int directionstate(int local_state);

    friend std::ostream &operator<<(std::ostream &out, const Spike &obs);
    friend std::istream &operator>>(std::istream &in, Spike &obs);
};

#endif