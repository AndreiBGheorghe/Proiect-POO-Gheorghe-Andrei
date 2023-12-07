#ifndef OOP_NORMAL_H
#define OOP_NORMAL_H

#include"../headers/Obstacle.h"

class Normal : public Obstacle {
private:
    int height;

public:
    ~Normal();
    explicit Normal(const int& local_length = 1, const int& local_points = 1, const int& local_height = 1);

    [[nodiscard]] int getheight() const;
    void setheight(int local_height);

    void citirenormal();
    void afisarenormal();

    friend std::ostream &operator<<(std::ostream &out, const Normal &obs);
    friend std::istream &operator>>(std::istream &in, Normal &obs);
};

#endif
