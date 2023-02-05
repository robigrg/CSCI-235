// Robi Gurung
// Professor Pavel Shostak
// Project IV
// 09 May 2022
#ifndef HUNPOLYNOMIAL_HPP
#define HUNPOLYNOMIAL_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
    1. Integer Coefficient
    2. Single Variable x
    3. Positive Integer Power
*/

class HunPolynomial
{
    public:
        HunPolynomial();
        HunPolynomial(std::initializer_list<int>);
        HunPolynomial(std::vector<int>);
        void Set(std::vector<int>);
        float operator()(float);
        HunPolynomial operator+(HunPolynomial);
        HunPolynomial operator-(HunPolynomial);
        HunPolynomial operator*(HunPolynomial);
        ~HunPolynomial();
        std::vector<int> getCoefficient();
    protected:

    private:
        std::vector<int> coefficient;
};
std::ostream& operator<<(std::ostream&, HunPolynomial&);
int abs(int);

#endif // HUNPOLYNOMIAL_HPP
