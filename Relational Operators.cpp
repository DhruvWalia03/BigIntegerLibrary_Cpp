/*------------------------RELATIONAL OPERATORS----------------------------------------------*/

/*
    This File Contains The Relational operators that are implemented in our Library.
    It contains all six basic relational operators i.e,
    Double equals to, Not equals to, Greater than , Greater than equals to, Less than,
    and Less than equals to.
*/


bool BigInteger::operator==(BigInteger b) {
    return equals((*this),b);
    // this represents the object that called the function and the argument passed was b
}

bool BigInteger::operator==(BigInteger b) {
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

