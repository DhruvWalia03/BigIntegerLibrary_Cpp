/*
* This File Contains All the Member Functions Both Public and Private that are
* used in the implementation of this library
* The Public Functions are accessible by the user where as the Private Functions
* are meant for internal calculations
*/


class BigInteger{

    private: // data accessible only within the class
        string number;
        bool sign; // true = positive false = negative
    public: // member functions of the Library
        BigInteger(); // default constructor
        BigInteger(string s); // parameterized constructor
        BigInteger(string s, bool sign); // parameterized constructor with string and sign
        BigInteger(long long n);
        void setNumber(string s);
        const string& getNumber(); // returns the number
        void setSign(bool sign);
        const bool getSign(); // returns the sign of the number
        BigInteger absolute();// returns absolute value
        void operator = (BigInteger b); // assignment operator
        // Relational Operators
        bool operator == (BigInteger b);
        bool operator != (BigInteger b);
        bool operator > (BigInteger b);
        bool operator < (BigInteger b);
        bool operator >= (BigInteger b);
        bool operator <= (BigInteger b);
        BigInteger maximum(BigInteger b);
        BigInteger minimum(BigInteger b);
        //Arithmetic Operators
        BigInteger operator + (BigInteger b);
        BigInteger operator - (BigInteger b);
        BigInteger operator * (BigInteger b);
        BigInteger operator / (BigInteger b);
        BigInteger operator % (BigInteger b);
        //Postfix/Prefix Operators
        BigInteger operator ++(); // prefix
        BigInteger  operator ++(int); // postfix
        BigInteger operator --(); // prefix
        BigInteger  operator --(int); // postfix
        //ShortHand Operators
        BigInteger operator += (BigInteger b);
        BigInteger operator -= (BigInteger b);
        BigInteger operator *= (BigInteger b);
        BigInteger operator /= (BigInteger b);
        BigInteger operator %= (BigInteger b);
        //Bitwise Operators
        BigInteger operator & (BigInteger b);
        BigInteger operator | (BigInteger b);
        BigInteger operator ^ (BigInteger b);
        BigInteger negation ();
        BigInteger leftshift ();
        BigInteger rightshift ();
        //Miscellaneous Operators
        BigInteger unaryminus(); // unary minus sign
        string toString(); // for conversion from BigInteger to string


    private:
        bool equals(BigInteger n1, BigInteger n2);
        bool less(BigInteger n1, BigInteger n2);
        bool greater(BigInteger n1, BigInteger n2);;
        string toString(long long n);
        long long toInt(string s);
        string add(string number1, string number2);
        string subtract(string number1, string number2);
        string multiply(string n1, string n2);
        pair<string, long long> divide(string dividend, long long divisor);
        string decToBin();
        BigInteger binToDec();

};

