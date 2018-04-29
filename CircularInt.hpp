#include <iostream>
using namespace std;

class CircularInt{
    int first;
    int last;
    int sum;
    
    public:
        CircularInt(int f, int l);
        ~CircularInt();
        
        friend ostream& operator<<(ostream&, const CircularInt&);
        bool operator >(const CircularInt& ) const;
        bool operator >=(const CircularInt& ) const;
        bool operator <(const CircularInt& ) const;
        bool operator <=(const CircularInt& ) const;
        bool operator ==(const CircularInt& ) const;
        bool operator!=(const CircularInt&);

        CircularInt& operator=(const CircularInt&);
        CircularInt& operator =(int);
        
        CircularInt& operator +=(int);
        CircularInt& operator -=(int);
        CircularInt& operator *=(int);
        CircularInt& operator /=(int);
        CircularInt& operator %=(int);
        CircularInt& operator ++();
        CircularInt& operator ++(int);
        
        CircularInt operator+(int);
        CircularInt operator+(const CircularInt&);
        friend CircularInt operator+(int,const CircularInt&);
        
        CircularInt operator-();
        CircularInt operator-(int);
        CircularInt operator-(const CircularInt&);
        friend CircularInt operator-(int,const CircularInt&);
        
        CircularInt operator*(int);
        CircularInt operator*(const CircularInt&);
        friend CircularInt operator*(int,const CircularInt&);
    
        int operator /(int);
        //CircularInt operator/(int);
        CircularInt operator/(const CircularInt&);
        friend CircularInt operator/(int,const CircularInt&);
        int check(int x);
};