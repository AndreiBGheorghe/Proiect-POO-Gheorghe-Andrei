#ifndef OOP_NEGATIVENR_H
#define OOP_NEGATIVENR_H

#include <iostream>
#include <stdexcept>

class NegativeNr : public std::runtime_error {
public:
    NegativeNr() : std::runtime_error("Numarul nu poate fi mai mic decat zero!") {}
};

#endif //OOP_NEGATIVENR_H
