#include "Fixed.hpp"
#include <iostream>
#include <cstring> // memcpy

Fixed::Fixed() : fixedPointNum_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : fixedPointNum_(num) {
    std::cout << "Int constructor called" << std::endl;
    if (num >= 0)
        setRawBits(num << fractionalBits_);
    else {
        int rawNum = ~(num - 1);
        int raw = (rawNum << fractionalBits_) * -1;
        setRawBits(raw);
    }
}

// 固定小数点にするために、与えられた浮動小数点を変換する必要がある。
// 浮動小数点から、仮数部と指数部を分ける。指数部を求める。
// 仮数部を右シフトすることで整数化する。
// 整数化した仮数部から、整数化の際に移動した右シフト文と固定小数点の位置(fractionalBits)右シフトする。
// 
Fixed::Fixed(const float fnum) : fixedPointNum_(0) {
    std::cout << "Float constructor called" << std::endl;
    uint32_t bits;
    memcpy(&bits, &fnum, sizeof(fnum));
    uint32_t sign      = (bits >> kFloatSignBitPos) & 0x1;
    uint32_t exponent  = (bits >> kFloatExponentBitPos) & 0xFF;
    uint32_t fraction  = bits & 0x7FFFFF;
    uint32_t mantissa = kFloatHiddenBit | fraction;
    int shift = ((int)exponent - kBias) + fractionalBits_- kFloatExponentBitPos;
    int raw_value;
    if (shift >= 0)
        raw_value = mantissa << shift;
    else
        raw_value = mantissa >> (-shift);
    if (sign)
        raw_value = -raw_value;
    setRawBits(raw_value);
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

int countLeadingZero(uint32_t x) {
    if (x == 0) 
        return 32;
    int count = 0;
    uint32_t mask = 1u << 31;
    while ((x & mask) == 0) {
        count++;
        mask >>= 1; // 右に1ビットずらす
    }
    return count;
}

float Fixed::toFloat(void) const {
    uint32_t rawVal = getRawBits();
    unsigned sign = 0u;
    if (rawVal < 0) {
        sign = 1u;
        rawVal *= -1;
    }
    if (rawVal == 0u) {
        uint32_t bits = (sign << 31);
        float ret;
        std::memcpy(&ret, &bits, sizeof(ret));
    }
    int digit = kFixedPointBits - countLeadingZero(rawVal) - 1;
    int expornent = digit - fractionalBits_ + kBias;
    int rshift = digit - kFloatExponentBitPos;
    unsigned int fraction;
    if (rshift >= 0) {
        fraction = rawVal >> rshift;
    } else {
       fraction = rawVal << -rshift;
    }
}

int Fixed::toInt(void) const {
    int rawVal = getRawBits();
    int newVal = (rawVal >> fractionalBits_);
    return newVal;
}
