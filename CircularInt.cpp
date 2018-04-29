#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#include "CircularInt.hpp"

CircularInt :: CircularInt(int f, int l){
    this -> first = f;
    this -> last = l;
    this -> sum = f;
}

CircularInt::~CircularInt() {
}

int CircularInt :: check(int x){
    if (x < this -> first){
        x = this -> last + x;
    } 
    else if (x > this -> last){
        x = x % (this -> last) ;
    }
    return x;
}   

ostream&  operator<<(ostream& out, const CircularInt& a){
    return out << a.sum;
}

bool CircularInt::operator >(const CircularInt & num) const {
    return this -> sum > num.sum;
}
bool CircularInt::operator >(int x) {
    return this -> sum > x;
}

bool CircularInt::operator >=(const CircularInt & num) const {
        return this ->sum >= num.sum;
}
bool CircularInt::operator >=(int x) {
        return this ->sum >= x;
}

bool CircularInt::operator <(const CircularInt & num) const {
    return this ->sum < num.sum;
}
bool CircularInt::operator <(int x) {
    return this ->sum < x;
}

bool CircularInt::operator <=(const CircularInt & num) const {
    return this -> sum <= num.sum;
}
bool CircularInt::operator <=(int x) {
    return this -> sum <= x;
}

bool CircularInt:: operator ==(const CircularInt& num ) const{
    return ((this -> sum == num.sum) && (this -> first == num.first) && (this -> last == num.last));
}
bool CircularInt:: operator ==(int x ){
    return (this -> sum == x);
} 

bool CircularInt :: operator != (const CircularInt& num){
      if ((this -> sum) == num.sum)
          if ((this -> first) == num.first)
              if ((this -> last) == num.last)
                 return false; 
      return true;
}
bool CircularInt :: operator != (int x){
    return (this -> sum != x);
}

CircularInt& CircularInt :: operator=(const CircularInt& num){
    this->first = num.first;
    this->last = num.last;
    this->sum = num.sum;
    return *this;
}
CircularInt& CircularInt::operator=(int x) {
    this -> sum =check(x) ;
    return *this;
}

CircularInt& CircularInt::operator +=( int x) {
    this -> sum = check((this -> sum) + x);
    return *this;
}
CircularInt& CircularInt::operator +=(CircularInt& num) {
    return operator +=(num.sum);
}

CircularInt& CircularInt::operator -=( int x) {
    this -> sum = check((this -> sum) - x);
    return *this;
}
CircularInt& CircularInt::operator -=(CircularInt& num) {
    return operator -=(num.sum);
}

CircularInt& CircularInt::operator *=(int x) {
    this-> sum =  check((this-> sum)*x);
     return *this;
}
CircularInt& CircularInt::operator *=(CircularInt& num) {
    this -> sum *= num.sum;
    check(this->sum);
    return *this;
}

CircularInt& CircularInt::operator /=( int x) {
    this-> sum =  check((this-> sum)/x);
    return *this;
}
CircularInt& CircularInt::operator /=(CircularInt& num){
    return operator /=(num.sum);
}

CircularInt& CircularInt::operator %=( int x) {
    this -> sum = (this -> sum % x) % this -> last;
    return *this;
}

CircularInt& CircularInt::operator++() {
    this -> sum = check(this -> sum + 1);
    return *this;
}
CircularInt& CircularInt::operator++(int x) {
    CircularInt temp{this-> first,this-> last};
    this-> sum = check(++this-> sum);
    return temp;
}

CircularInt& CircularInt::operator--() {
    this -> sum = check(this -> sum - 1);
    return *this;
}
CircularInt& CircularInt::operator--(int x) {
    CircularInt temp{this-> first,this-> last};
    this-> sum = check(--this-> sum);
    return temp;
}

CircularInt CircularInt :: operator+(int x){
    CircularInt temp{this-> first,this-> last};
    temp.sum = this -> sum;
     temp.check(temp.sum + x);
    return temp;
}
CircularInt operator+(int x, const CircularInt& num){
    CircularInt temp{num.first,num.last};
    temp.sum = num.sum;
    temp.check(temp.sum + x);
    return temp;
}
CircularInt CircularInt :: operator+(const CircularInt& num){
    CircularInt temp{this-> first, this-> last};
    temp.sum = this ->sum;
    temp.check(temp.sum + num.sum);
    return temp;
}

CircularInt CircularInt :: operator-(){
    CircularInt temp{this-> first,this-> last};
    temp.sum =  check(-(this-> sum));
    return temp;
     
 }
CircularInt CircularInt :: operator-(int x){
    CircularInt temp{this-> first,this-> last};
    temp.sum = this -> sum;
    temp -= x;
    return temp;
}
CircularInt operator-(int x, const CircularInt& num){
    CircularInt temp{num.first,num.last};
    temp.sum = num.sum;
    temp = -(temp-x);
    return temp;
}
CircularInt CircularInt :: operator-(const CircularInt& num){
    CircularInt temp{this-> first, this-> last};
    temp.sum = check(this -> sum - num.sum);
    return temp;
}

CircularInt CircularInt :: operator*(int x){
    CircularInt temp{this-> first,this-> last};
    temp.sum = this -> sum;
    temp.sum = temp.check(temp.sum*x);
    return temp;
}
CircularInt operator*(int x, const CircularInt& num){
    CircularInt temp{num.first,num.last};
    temp.sum = num.sum;
    temp.sum = temp.check(temp.sum*x);
    return temp;
}
CircularInt CircularInt :: operator*(const CircularInt& num){
    CircularInt temp{this-> first, this-> last};
    temp.sum = this ->sum;
    temp.sum = temp.check(temp.sum * num.sum);
    return temp;
}

/*CircularInt CircularInt :: operator/(int x){
    CircularInt temp{this-> first,this-> last};
    temp.sum = this -> sum;
    temp /= x;
    return temp;
}*/

CircularInt operator/(int x, const CircularInt& num){
    CircularInt temp{num.first,num.last};
    temp.sum = num.sum;
    temp /=x;
    return temp;
}

CircularInt CircularInt :: operator/(const CircularInt& num){
    CircularInt temp{this-> first, this-> last};
    temp.sum = this ->sum;
    temp /= num.sum;
    return temp;
}
 
int CircularInt:: operator /( int x){
    if(this -> sum % x == 0){
        this -> sum = (this -> sum/x) % this -> last;
        return this -> sum;
    }
    else{
        cout<<"There is no number x in {"<<this -> first <<", "<< this->last <<"} such that x*"<<x<<"="<<this->sum;
        //throw logic_error();
    }
}

