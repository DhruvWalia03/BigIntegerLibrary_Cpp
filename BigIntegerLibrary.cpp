/*
  @Code By Dhruv Walia (IIT ISM DHANBAD 2023)
  Big Integer library in C++ implementation.
 */
#include<iostream>
#include<sstream>
#include<string>
#include<math>

#define MAX_LENGTH 10000 // the maximum length of the string
//which means the BigIntegers can vary up to 10^(max_length)

using namespace std;

class BigInteger{

    private: // data accessible only within the class
        string number;
        bool sign; // true = positive false = negative
    public: // member functions of the Library
        BigInteger(); // default constructor
        BigInteger(string s); // parameterized constructor
        BigInteger(string s, bool sign); // parameterized constructor with string and sign
        BigInteger(int n);
        void setNumber(string s);
        const string& getNumber(); // returns the number
        void setSign(bool sign)
        const bool& getSign(); // returns the sign of the number
        BigInteger absolute();// returns absolute value
        // Relational Operators
        void operator = (BigInteger b);
        bool operator == (BigInteger b);
        bool operator != (BigInteger b);
        bool operator > (BigInteger b);
        bool operator < (BigInteger b);
        bool operator >= (BigInteger b);
        bool operator <= (BigInteger b);
        //Arithmetic Operators
        BigInteger operator + (BigInteger b);
        BigInteger operator - (BigInteger b);
        BigInteger operator * (BigInteger b);
        BigInteger operator / (BigInteger b);
        BigInteger operator % (BigInteger b);
        //Postfix/Prefix Operators
        BigInteger& operator ++(); // prefix
        BigInteger  operator ++(int); // postfix
        BigInteger& operator --(); // prefix
        BigInteger  operator --(int); // postfix
        //ShortHand Operators
        BigInteger& operator += (BigInteger b);
        BigInteger& operator -= (BigInteger b);
        BigInteger& operator *= (BigInteger b);
        BigInteger& operator /= (BigInteger b);
        BigInteger& operator %= (BigInteger b);
        //Miscellaneous Operators
        BigInteger operator -(); // unary minus sign
        operator string(); // for conversion from BigInteger to string


    private:
        bool equals(BigInteger n1, BigInteger n2);
        bool less(BigInteger n1, BigInteger n2);
        bool greater(BigInteger n1, BigInteger n2);;
        string toString(long long n);
        long long toInt(string s);
        string add(string number1, string number2);
        string subtract(string number1, string number2);
        string multiply(string n1, string n2);
        pair<string, long long> divide(string dividend, long long divisor)

};

int main(){
    // Write your code here to Deal with BigIntegers of Length Up to 10^(10000)
    return 0;
}

/*------------------------------------------------------------------------------*/

BigInteger::BigInteger() {
    //to initialize with zero
    number = "0";
    sign = true;
}

BigInteger::BigInteger(string s) {
    //to initialize with string containing the sign
    if(s[0]!='+' || s[0]!='-'){ //unsigned integer
        setNumber(s);
        sign = true;
    } else { //signed integer
        setNumber(s.substr(1));
        sign = (s[0]!='-');
    }
}

BigInteger::BigInteger(string s, bool sign) {
    //to initialize with string with sign given separately
    setNumber(s);
    setSign(sign);
}

BigInteger::BigInteger(int n) {
    // to initialize with an integer
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    if(s[0]!='+' || s[0]!='-'){ //unsigned integer
        setNumber(s);
        setSign(true);
    } else { //signed integer
        setNumber(s.substr(1));
        setSign(s[0]!='-');
    }
}

void BigInteger::setNumber(string s) {
    number = s;
}

const string& BigInteger::getNumber() {
    return number;
}

void BigInteger::setSign(bool s) {
    sign = s;
}

const string& BigInteger::getSign() {
    return sign;
}

void BigInteger::operator=(BigInteger b) {
    setNumber(b.getNumber());
    setSign(b.getSign());
}

/*------------------------RELATIONAL OPERATORS----------------------------------------------*/

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

/*------------------------ARITHMETIC OPERATORS----------------------------------------------*/

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
            sum.setNumber(sub(getNumber(),b.getNumber()));
            sum.setSign(getSign());
        }
        else // B>A
        {
            sum.setNumber(sub(b.getNumber(),getNumber()));
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

/*------------------------POSTFIX/PREFIX OPERATORS------------------------------------------*/

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

/*------------------------SHORTHAND OPERATORS----------------------------------------------*/

BigInteger BigInteger::operator+= (BigInteger b) {
    (*this) = (*this) + b;
    return (*this);
}

BigInteger BigInteger::operator-= (BigInteger b) {
    (*this) = (*this) - b;
    return (*this);
}

BigInteger BigInteger::operator*= (BigInteger b) {
    (*this) = (*this) * b;
    return (*this);
}

BigInteger BigInteger::operator/= (BigInteger b) {
    (*this) = (*this) / b;
    return (*this);
}

BigInteger BigInteger::operator%= (BigInteger b) {
    (*this) = (*this) % b;
    return (*this);
}

/*------------------------MISCELLANEOUS OPERATORS-------------------------------------------*/

BigInteger BigInteger::operator- (BigInteger b) {
    setSign(!getSign());
    return (*this)
}

string BigInteger::operatorstring() {
    string sign = (getSign()) ? "" : "-";
    // if we have positive then no need of sign else - negative sign
    sign+= number;

    return sign;
}

/*------------------------ PRIVATE MEMBER METHODS ------------------------------------------*/

bool BigInteger::equals(BigInteger b1,BigInteger b2) {
    return (b1.getNumber() == b2.getNumber()) &&
            (b1.getSign() == b2.getSign());
}

bool BigInteger::less(BigInteger b1,BigInteger b2) {
    bool s1 = b1.getSign();
    bool s2 = b2.getSign();
    string n1 = b1.getNumber();
    string n2 = b2.getNumber();

    if(s1 == false && s2 == true) // b1 is -ve and b2 is +ve
        return true;

    if(s1 == true && s2 == false) // b1 is +ve and b2 is -ve
        return false;

    if(s1) // both positive
    {
        if(n1.length() < n2.length())
            return true;
        if(n1.length() > n2.length())
            return false;
        return n1 < n2;
    }
}

bool BigInteger::greater(BigInteger b1,BigInteger b2) {
    bool s1 = b1.getSign();
    bool s2 = b2.getSign();
    string n1 = b1.getNumber();
    string n2 = b2.getNumber();

    if(s1 == false && s2 == true) // b1 is -ve and b2 is +ve
        return false;

    if(s1 == true && s2 == false) // b1 is +ve and b2 is -ve
        return true;

    if(s1) // both positive
    {
        if(n1.length() < n2.length())
            return false;
        if(n1.length() > n2.length())
            return true;
        return n1 > n2;
    }
}

string BigInteger::toString(long long n) {
    stringstream sstream;
    string s;

    sstream << n;
    sstream >> s;

    return s;
}

long long BigInteger::toInt(string s) {
    long long sum = 0;

    for(int i=0; i<s.length(); i++)
        sum = (sum*10)+ (s[i]-'0');

    return sum;
}

string BigInteger::add(string num1,string num2) {
    string result = (num1.length() > num2.length)? num1 : num2;
    char carry = '0';
    int diffInLength = abs((int)(num1.size()-num2.size()));

// we will add numbers character wise as in digital electronics

    if(num1.size() > num2.size())
        num2.insert(0,diffInLength,'0'); // put zeros at start of the smaller number
    else
        num1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number

    for(int i=num1.size()-1; i>=0; --i){
        result[i] = (carry-'0')+(num1[i]-'0')+(num2[i]-'0')+'0';

        if(i!=0) {
            if(result[i] > '9')
                result[i] -= 10,carry = '1';
            else carry = '0';
        }
    }
    if(result[0] > '9')
        result[0] -= 10,result.insert(0,1,'1');

    return result;
}

string BigInteger::subtract(string num1,string num2) {
    string result = (num1.length() > num2.length)? num1 : num2;
    int diffInLength = abs((int)(num1.size()-num2.size()));

// we will subtract numbers character wise as in digital electronics

    if(num1.size() > num2.size())
        num2.insert(0,diffInLength,'0'); // put zeros at start of the smaller number
    else
        num1.insert(0,diffInLength,'0'); // put zeros at start of the smaller number

    for(int i=num1.size()-1; i>=0; --i)
    {
        if(num1[i]<num2[i]) {
            num1[i] += 10;
            num1[i-1]--;
        }
        result[i] = (num1[i]-'0')-(num2[i]-'0')+'0';
    }

    while(result[0]=='0' && result.length()>1) // erase the leading zeros
        result.erase(0,1);

    return result;
}

string BigInteger::multiply(string n1, string n2) {
    if(n1.length() > n2.length())
        n1.swap(n2);

// we will multiply numbers character wise as in digital electronics

    string result = "0";
    for(int i=n1.length()-1; i>=0; --i)
    {
        string temp = n2;
        int currentDigit = n1[i]-'0';
        int carry = 0;

        for(int j = temp.length()-1; j>=0; --j)
        {
            temp[j] = ((temp[j]-'0')*currentDigit) + carry;

            if(temp[j] > 9)
                carry = (temp[j]/10), temp[j] = (temp[j]%10);
            else carry = 0;

            temp[j] += '0'; //back to string mode
        }

        if(carry > 0)
            temp.insert(0,1,carry+'0');
// for shifting the number to left as next digit is at tens place and so on.
        temp.append((n1.length()-i-1),'0');
// finallu store it in the result string.
        result = add(res, temp); //O(n)
    }
    while(result[0]=='0' && result.length()>1) // erase the leading zeros
        result.erase(0,1);

    return result;
}

pair<string,long long> BigInteger::divide(string dividend, long long divisor) {
    long long remainder = 0;
    string quotient;
    quotient.resize(MAX_LENGTH);

    for(int i = 0,l = dividend.length(); i < l; i++) {
        remainder = (remainder * 10) + ( dividend[i] - '0');
        quotient[i] = remainder/divisor + '0';
        remainder %= divisor;
    }
    quotient.resize(n.length());
// removing leading zeros if any
    while(quotient[0] == '0' && quotient.length() != 1)
        quotient.erase(0,1);
// to check if the string has become to zero which means dividend < divisor
    if(quotient.length() == 0)
        quotient = "0";

    return {quotient,remainder};
}
