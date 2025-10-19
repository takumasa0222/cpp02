#include <ostream>
#include <stdint.h>
class Fixed {
    public:
    Fixed();
    Fixed(int num);
    Fixed(float fnum);
    ~Fixed();
    Fixed(Fixed &source);
    Fixed(const Fixed &source);
    Fixed& operator=(const Fixed &source);
    bool operator>(const Fixed& rightVal) const;
    bool operator<(const Fixed& rightVal) const;
    bool operator>=(const Fixed& rightVal) const;
    bool operator<=(const Fixed& rightVal) const;
    bool operator==(const Fixed& rightVal) const;
    bool operator!=(const Fixed& rightVal) const;
    Fixed operator+(const Fixed& rightVal) const;
    Fixed operator-(const Fixed& rightVal) const;
    Fixed operator*(const Fixed& rightVal) const;
    Fixed operator/(const Fixed& rightVal) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    private:
    int fixedPointNum_;
    static const int fractionalBits_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& source);
