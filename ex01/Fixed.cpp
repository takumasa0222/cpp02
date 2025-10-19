#include "Fixed.hpp"
#include <iostream>
#include <cstring> // memcpy
# include <cmath>

Fixed::Fixed() : fixedPointNum_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : fixedPointNum_(num << fractionalBits_) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fnum) : fixedPointNum_(0) {
    std::cout << "Float constructor called" << std::endl;
    int rawVal = static_cast<int>(roundf(fnum * (1 << fractionalBits_)));
    setRawBits(rawVal);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
} 

Fixed::Fixed(const Fixed& source) {
    std::cout << "Copy constructor called" << std::endl;
    fixedPointNum_ = source.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& source) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &source)
        return *this;
    fixedPointNum_ = source.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed &source) {
    os << source.toFloat();
    return os;
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called" << std::endl;
    return fixedPointNum_;
}

void Fixed::setRawBits(int const raw) {
    fixedPointNum_ = raw;
}

float Fixed::toFloat(void) const {
    return (float)getRawBits() / (1 << fractionalBits_);
}

int Fixed::toInt(void) const {
    int rawVal = getRawBits();
    int newVal = (rawVal >> fractionalBits_);
    return newVal;
}
