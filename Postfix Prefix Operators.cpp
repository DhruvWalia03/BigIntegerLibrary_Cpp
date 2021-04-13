/*------------------------POSTFIX/PREFIX OPERATORS------------------------------------------*/

/*
    This file contain the prefix and postfix increment and decrement operators.
*/


BigInteger BigInteger::operator++() { //prefix
    (*this) = (*this) + 1; // used addition
    return (*this);
}

BigInteger BigInteger::operator++(int)) { //postfix
    BigInteger store = (*this);
    (*this) = (*this) + 1; // used addition

    return store;
}

BigInteger BigInteger::operator--() { //prefix
    (*this) = (*this) - 1; // used subtraction
    return (*this);
}

BigInteger BigInteger::operator--(int)) { //postfix
    BigInteger store = (*this);
    (*this) = (*this) - 1; // used subtraction

    return store;
}
