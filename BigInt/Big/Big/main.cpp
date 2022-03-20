#include <iostream>

class HugeInt {
    std::string value;
    friend std::istream& operator>>(std::istream&, HugeInt&);
    friend std::ostream& operator<<(std::ostream&, const HugeInt&);

    public:
        HugeInt();
        HugeInt(const HugeInt&);
        HugeInt(const int&);
        HugeInt(const std::string&);
        

        HugeInt& operator=(const HugeInt&);
        HugeInt& operator=(const int&);
        HugeInt& operator=(const std::string&);

        HugeInt operator+(const HugeInt&) const;
        HugeInt operator*(const HugeInt&) const;
        HugeInt operator-(const HugeInt&) const;
        HugeInt operator-(const int&) const;
        bool operator==(const int&) const;
        bool operator!=(const int&) const;
        bool operator==(const HugeInt&) const;
   

};

HugeInt::HugeInt() {
    value = "0";

}


HugeInt::HugeInt(const HugeInt& num) {
    value = num.value;

}


HugeInt::HugeInt(const int& num) {
    value = std::to_string(num);
 
}


HugeInt::HugeInt(const std::string& num) {
      value = num;
}

bool HugeInt::operator==(const HugeInt& num) const {
    return (value == num.value);
}

bool HugeInt::operator==(const int& num) const {
    return *this == HugeInt(num);
}

bool HugeInt::operator!=(const int& num) const {
    return !(*this == HugeInt(num));
}





HugeInt& HugeInt::operator=(const int& num) {
    HugeInt temp(num);
    value = temp.value;

    return *this;
}


HugeInt& HugeInt::operator=(const std::string& num) {
    HugeInt temp(num);
    value = temp.value;

    return *this;
}


HugeInt HugeInt::operator-(const HugeInt& num) const {


    HugeInt result;   
    std::string l1, l2;
    
        l1 = this->value;
        l2 = num.value;


    result.value = "";
    short difference;
    long i, j;
    for (i = l1.size() - 1; i >= 0; i--) {
        difference = l1[i] - l2[i];
        if (difference < 0) {
            for (j = i - 1; j >= 0; j--) {
                if (l1[j] != '0') {
                    l1[j]--;    
                    break;
                }
            }
            j++;
            while (j != i) {
                l1[j] = '9';   
                j++;
            }
            difference += 10;   
        }
        result.value = std::to_string(difference) + result.value;
    }


  

    return result;
}


HugeInt HugeInt::operator-(const int& num) const {
    return *this - HugeInt(num);
}


HugeInt HugeInt::operator+(const HugeInt& num) const {


    std::string l1, l2;
    l1 = num.value;
    l2 = this->value;
    HugeInt result;      
    result.value = "";  
    short carry = 0, sum;

    for (long i = l1.size() - 1; i >= 0; i--) {
        sum = l1[i] - '0' + l2[i] - '0' + carry;
        result.value = std::to_string(sum % 10) + result.value;
        carry = sum / (short) 10;
    }
    if (carry)
        result.value = std::to_string(carry) + result.value;


    return result;
}
HugeInt& HugeInt::operator=(const HugeInt& num) {
    value = num.value;
    return *this;
}



HugeInt HugeInt::operator*(const HugeInt& num) const {
    if (*this == 0 or num == 0)
        return HugeInt(0);
    if (*this == 1)
        return num;
    if (num == 1)
     return *this;

    HugeInt product("0");
    std::cout<<num.value;
    HugeInt x=num.value;
    int i=1;
    while(x!=0) {std::cout<<"\nme";
        x=x-1;
        product=product+num.value+this->value;
        std::cout<<product;
    }
    /*
    while( x-1!=0){
        std::cout<<++i;
        product=num.value+this->value;
        
        x=num-1;
    }
    */

    return 0;
}


std::istream& operator>>(std::istream& in, HugeInt& num) {
    std::string input;
    in >> input;
    num = HugeInt(input); 

    return in;
}


std::ostream& operator<<(std::ostream& out, const HugeInt& num) {

    out << num.value;

    return out;
}


int main(){
    HugeInt t1;
    HugeInt t2;
    HugeInt t3;
    std::cin>>t1>>t2>>t3;
    std::cout<<std::endl;
    std::cout<<t1+t2<<std::endl;
    std::cout<<t3*t1;
}

