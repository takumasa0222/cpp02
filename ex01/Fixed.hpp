
class Fixed {
    public:
    Fixed();
    Fixed(int num);
    Fixed(float fnum);
    ~Fixed();
    Fixed(Fixed &source);
    void operator=(Fixed &source);
    void operator<<(Fixed &source);
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
