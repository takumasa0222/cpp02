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
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;

    private:
    int fixedPointNum_;
    static const int fractionalBits_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& source);