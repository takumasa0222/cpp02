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
    static const int kBias = 127;
    static const int kFloatSignBitPos = 31;
    static const int kFloatExponentBitPos = 23;
    static const int kFloatExponentBits = 8;
    static const int kFloatFractionBits = 23;
    static const int kFixedPointBits = 32;
    static const uint32_t kFloatHiddenBit = (1u << 23);
};

std::ostream& operator<<(std::ostream& os, const Fixed& source);