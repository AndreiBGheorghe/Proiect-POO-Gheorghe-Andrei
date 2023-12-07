#ifndef OOP_HOLE_H
#define OOP_HOLE_H

#include"../headers/Obstacle.h"

class Hole : public Obstacle {
private:
    int depth;

public:
    ~Hole();
    explicit Hole(const int& local_length = 1, const int& local_points = 1, const int& local_depth = 1);

    [[nodiscard]] int getdepth() const;
    void setdepth(int local_depth);

    void citirehole();
    void afisarehole();

    friend std::ostream &operator<<(std::ostream &out, const Hole &obs);
    friend std::istream &operator>>(std::istream &in, Hole &obs);
};

#endif
