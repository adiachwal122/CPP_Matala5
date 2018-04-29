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

        CircularInt& operator =(int);
        CircularInt& operator +=(int);
        CircularInt& operator -=(int);
        CircularInt& operator *=(int);
        CircularInt& operator /=(int);
        CircularInt& operator %=(int);
        CircularInt& operator ++();
        CircularInt& operator ++(int);
        
        int operator+(CircularInt&);
        int operator-();
        int operator /(int);
        friend int operator-(int , CircularInt&);
        
        int check(int x);
};