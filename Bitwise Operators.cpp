/*
*   This is the file for Bitwise Operators.
*   I implemented bitwise and, or, xor, not and left and right shift operators.
*   But these operators work only on positive big integers.
*/
/*--------------------------BITWISE OPERATORS----------------------------------------------*/

BigInteger BigInteger::operator&(BigInteger b) {
    BigInteger a = (*this);
    // Converting the Big Integer into Binary
    string a1 = a.decToBin();
    string b1 = b.decToBin();
    string result="";
    int diffInLength = abs((int)(a1.size()-b1.size()));

    if(a1.size() > b1.size())
        b1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number
    else
        a1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number

    int len = a1.length();
    for(int i = 0; i < len; i++)
    {
        if(a1[i]=='1' && b1[i]=='1')
            result += '1';
        else result += '0';
    }
    // Converting binary output into decimal
    BigInteger result_dec = BigInteger(result).binToDec();
    // Converting to Big Integer;
    return result_dec;
}

BigInteger BigInteger::operator|(BigInteger b) {
    BigInteger a = (*this);
    // Converting the Big Integer into Binary
    string a1 = a.decToBin();
    string b1 = b.decToBin();
    string result="";
    int diffInLength = abs((int)(a1.size()-b1.size()));

    if(a1.size() > b1.size())
        b1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number
    else
        a1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number

    int len = a1.length();
    for(int i = 0; i < len; i++)
    {
        if(a1[i]=='1' || b1[i]=='1')
            result += '1';
        else result += '0';
    }
    // Converting binary output into decimal
    BigInteger result_dec = BigInteger(result).binToDec();
    // Converting to Big Integer;
    return result_dec;
}

BigInteger BigInteger::operator^(BigInteger b) {
    BigInteger a = (*this);
    // Converting the Big Integer into Binary
    string a1 = a.decToBin();
    string b1 = b.decToBin();
    string result="";
    int diffInLength = abs((int)(a1.size()-b1.size()));

    if(a1.size() > b1.size())
        b1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number
    else
        a1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number

    int len = a1.length();
    for(int i = 0; i < len; i++)
    {
        if((a1[i]=='1' && b1[i]=='0') || (a1[i]=='0' && b1[i]=='1'))
            result += '1';
        else result += '0';
    }
    // Converting binary output into decimal
    BigInteger result_dec = BigInteger(result).binToDec();
    // Converting to Big Integer;
    return result_dec;
}

BigInteger BigInteger::negation() {
    BigInteger a = (*this);
    // Converting the Big Integer into Binary
    string a1 = a.decToBin();
    string result="";
    int len = a1.length();

    for(int i = 0; i < len; i++)
    {
        if(a1[i]=='1')
            result += '0';
        else result += '1';
    }
    // Converting binary output into decimal
    BigInteger result_dec = BigInteger(result).binToDec();
    // Converting to Big Integer;
    return result_dec;
}

BigInteger BigInteger::leftshift() {
    return (*this)*2;
}

BigInteger BigInteger::rightshift() {
    return (*this)/2;
}
