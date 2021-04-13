/*------------------------RELATIONAL OPERATORS----------------------------------------------*/

/*
    This File Contains The Relational operators that are implemented in our Library.
    It contains all six basic relational operators i.e,
    Double equals to, Not equals to, Greater than , Greater than equals to, Less than,
    and Less than equals to. Also added MAX and MIN between two Big integers function.
*/


bool BigInteger::operator==(BigInteger b) {
    return equals((*this),b);
    // this represents the object that called the function and the argument passed was b
}

bool BigInteger::operator!=(BigInteger b) {
    return !equals((*this),b);
    // this represents the object that called the function and the argument passed was b
}

bool BigInteger::operator>=(BigInteger b) {
    return equals((*this),b) || greater((*this),b);
    // this represents the object that called the function and the argument passed was b
}

bool BigInteger::operator<=(BigInteger b) {
    return equals((*this),b) || less((*this),b);
    // this represents the object that called the function and the argument passed was b
}

bool BigInteger::operator>(BigInteger b) {
    return greater((*this),b);
    // this represents the object that called the function and the argument passed was b
}

bool BigInteger::operator<(BigInteger b) {
    return less((*this),b);
    // this represents the object that called the function and the argument passed was b
}

BigInteger BigInteger::maximum(BigInteger b) {
    // if this big integer is greater or equals B we return this else B
    if(greater((*this),b) || equals((*this),b))
        return (*this);
    return b;
}

BigInteger BigInteger::minimum(BigInteger b) {
    // if this big integer is less or equals B we return this else B
    if(less((*this),b) || equals((*this),b))
        return (*this);
    return b;
}
