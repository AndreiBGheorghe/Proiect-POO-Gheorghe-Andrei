#ifndef OOP_OBSTACLE_H
#define OOP_OBSTACLE_H

class Obstacle {
protected:
    int length;
    int points;

public:
    ~Obstacle();
    explicit Obstacle(const int& local_length = 1 , const int& local_points = 1);

    [[nodiscard]] int getlength() const;
    void setlength(int local_length);

    [[nodiscard]] int getpoints() const;
    void setpoints(int local_points);

    virtual void citire();
    virtual void afisare();

    [[nodiscard]] virtual Obstacle* clone() const;

    friend std::ostream &operator<<(std::ostream &out, const Obstacle &obs);
    friend std::istream &operator>>(std::istream &in, Obstacle &obs);
};

#endif
