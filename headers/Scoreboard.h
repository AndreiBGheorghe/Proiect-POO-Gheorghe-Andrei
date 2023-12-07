#ifndef OOP_SCOREBOARD_H
#define OOP_SCOREBOARD_H

class Scoreboard {
private:
    std::string name;
    int score;

public:
    ~Scoreboard();
    explicit Scoreboard(const std::string& local_name = "Player1", const int& local_score = 0);

    [[nodiscard]] std::string getname() const;
    void setname(const std::string &local_name);

    [[nodiscard]] int getscore() const;
    void setscore(const int &local_score);

    static bool valid_name(const std::string &local_name);

    friend std::ostream &operator<<(std::ostream &out, const Scoreboard &sb);
    friend std::istream &operator>>(std::istream &in, Scoreboard &sb);
};

#endif
