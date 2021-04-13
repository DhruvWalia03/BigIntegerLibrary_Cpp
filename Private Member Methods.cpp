/*------------------------ PRIVATE MEMBER METHODS ------------------------------------------*/

/*
    These are the Member Functions that are used for internal Calculations and not
    accessible by the user. We internally use digital electronics techniques to
    compute the sum, difference, product, and division of two numbers.
*/


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
