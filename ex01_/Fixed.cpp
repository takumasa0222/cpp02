
// 値を取得する
// 非負の数へ変換する
// 仮数部を取得する

float toFloat(void) const {
    int rawVal = getRawbits();
    if (rawVal < 0)
    rawVal *= -1;
    int digit = kFixedPointBits - countLeadingZero() -1;
    int expornent = digit - fractionlBits_ + kFloat_Eeponent_bias;
    


}

int toInt(void) const {
    int rawVal = getRawbits();
    int newVal = (rawVal >> fractionalBits_);
    return newVal;
}
