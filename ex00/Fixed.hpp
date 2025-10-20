
class Fixed {
    public:
    Fixed();
    ~Fixed();
    Fixed(Fixed &source);
    Fixed& operator=(const Fixed &source);
    int getRawBits() const;
    void setRawBits(int const raw);
    private:
    int fixedPointNum_;
    static const int fractionalBits_ = 8;
};
