/*------------------------ARITHMETIC OPERATORS----------------------------------------------*/

/*
    This file contains five basic arithmetic operations
    i.e, Addition , Subtraction , Multiplication , Division and Modulus.
*/


BigInteger BigInteger::operator+(BigInteger b) {
    BigInteger sum;
    if(getSign() == b.getSign()) // both positive or both negative
    {
        sum.setNumber(add(getNumber(),b.getNumber()));
        sum.setSign(getSign());
    }
    else // opposite signs
    {
        if(absolute() > b.absolute()) // A>B
        {
            sum.setNumber(subtract(getNumber(),b.getNumber()));
            sum.setSign(getSign());
        }
        else // B>A
        {
            sum.setNumber(subtract(b.getNumber(),getNumber()));
            sum.setSign(b.getSign());
        }
    }
    if(sum.getNumber() == "0")
        sum.setSign(true);
    return sum;
}

BigInteger BigInteger::operator-(BigInteger b) {
    // if B is negative then a - (-b) = a + b
    // if B is positive then a - (b) = a + (-b)
    b.setSign(!b.getSign());
    return (*this)+b;
}

BigInteger BigInteger::operator*(BigInteger b) {
    BigInteger mul;
    mul.setNumber(multiply(getNumber(),b.getNumber()));
    mul.setSign(getSign() == b.getSign());

    if(mul.getNumber() == "0")
        mul.setSign(true);

    return mul;
}

// WARNING: the Divisor must be within 64bit and not a BigInteger
BigInteger BigInteger::operator/(BigInteger b) {
    long long deno = toInt(b.getNumber());
    BigInteger quotient;

    quotient.setNumber(divide(getNumber(),deno).first);
    quotient.setSign(getSign() == b.getSign());

    if(quotient.getNumber() == "0")
        quotient.setSign(true);

    return quotient;
}

// WARNING: the Divisor must be within 64bit and not a BigInteger
BigInteger BigInteger::operator%(BigInteger b) {
    long long deno = toInt(b.getNumber());
    BigInteger remainder;

    remainder.setNumber(toString(divide(getNumber(),deno).second));
    remainder.setSign(getSign() == b.getSign());

    if(remainder.getNumber() == "0")
        remainder.setSign(true);

    return remainder;
}
