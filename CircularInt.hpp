#include <iostream>
using namespace std;
#include <string>
#include <sstream>

class CircularInt{
    int first;
    int last;
    int sum;
    
    public:
        CircularInt(int f, int l);
        ~CircularInt();
        
        friend ostream& operator<<(ostream&, const CircularInt&);
        int check(int x);
        
        bool operator >(const CircularInt& ) const;
        bool operator >(const int )const;
        
        bool operator >=(const CircularInt& ) const;
        bool operator >=(const int )const;
        
        bool operator <(const CircularInt& ) const;
        bool operator <(const int )const;
        
        bool operator <=(const CircularInt& ) const;
        bool operator <=(const int )const;
        
        bool operator ==(const CircularInt& ) const;
        bool operator ==(const int )const;
        
        CircularInt& operator=(const CircularInt&);
        CircularInt& operator=(int);
        
        bool operator!=(const CircularInt&);
        bool operator!=(int);

        
        
        CircularInt& operator +=(int);
        CircularInt& operator +=(CircularInt&);
        CircularInt& operator ++();
        CircularInt& operator ++(int);
        
        CircularInt& operator -=(int);
        CircularInt& operator -=(CircularInt&);
        CircularInt& operator --();
        CircularInt& operator --(int);
        
        CircularInt& operator *=(int);
        CircularInt& operator *=(CircularInt&);
        
        /*CircularInt& operator /=(int);
        CircularInt&operator /=(CircularInt&);*/
        
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
    
        CircularInt operator/ (int )const;
        CircularInt operator/ (CircularInt&)const;
        CircularInt& operator/=(int num);
    CircularInt& operator/=(CircularInt& other);
        friend CircularInt operator/(int, CircularInt& );
        
};
