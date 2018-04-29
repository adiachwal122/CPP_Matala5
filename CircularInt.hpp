#include <iostream>
using namespace std;
#include <string>
#include <sstream>

class CircularInt{
    int first;
    int last;
    int mod;
    public:
        int sum;

        CircularInt(int f, int l);
        CircularInt(const CircularInt&); // copy c'tor
        ~CircularInt();

        friend ostream& operator<<(ostream&, const CircularInt&);
        friend istream& operator>> (istream& , CircularInt& );

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
        bool operator!=(const int) const;

        
        CircularInt& operator +=(int);
        CircularInt& operator +=(CircularInt&);
        CircularInt& operator ++();
        CircularInt operator ++(int);
        
        CircularInt& operator -=(int);
        CircularInt& operator -=(CircularInt&);
        CircularInt& operator --();
        CircularInt operator --(int);
        
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
    inline ostream&  operator<<(ostream& out, const CircularInt& a){
        return out << a.sum;
    }
    
    inline istream& operator>> (istream& is, CircularInt& cirInt) {
        int current;
        is>>current;
	    cirInt.sum = current;
	    cirInt.sum = cirInt.check(cirInt.sum);
        return is;  
    }
    
    inline bool operator==(const int& nMember, const CircularInt& member){ return nMember == member.sum; }
    inline bool operator!=(const int& nMember, const CircularInt& member){ return nMember != member.sum;}
    inline bool operator< (const int& nMember, const CircularInt& member){ return nMember < member.sum; }
    inline bool operator> (const int& nMember, const CircularInt& member){ return  nMember > member.sum;}
    inline bool operator<=(const int& nMember, const CircularInt& member){ return nMember <= member.sum;}        inline bool operator>=(const int& nMember, const CircularInt& member){ return nMember >= member.sum;}
        
