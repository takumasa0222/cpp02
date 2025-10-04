#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixedPointNum_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
} 

Fixed::Fixed(Fixed& source) {
    std::cout << "Copy constructor called" << std::endl;
    fixedPointNum_ = source.getRawBits();
}

void Fixed::operator=(Fixed& source) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &source)
        return;
    fixedPointNum_ = source.getRawBits();
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointNum_;
}

void Fixed::setRawBits(int const raw) {
    fixedPointNum_ = raw;
}
