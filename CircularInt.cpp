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
    return sum > num.sum;
}

bool CircularInt::operator >=(const CircularInt & num) const {
        return sum >= num.sum;
}

bool CircularInt::operator <(const CircularInt & num) const {
    return sum < num.sum;
}

bool CircularInt::operator <=(const CircularInt & num) const {
        return sum <= num.sum;
}

bool CircularInt:: operator ==(const CircularInt& num ) const{
    return ((this -> sum == num.sum) && (this -> first == num.first) && (this -> last == num.last));
}

CircularInt& CircularInt::operator =(int x) {
    this -> sum = x;
    return *this;
}

CircularInt& CircularInt::operator +=( int x) {
    this -> sum = check((this -> sum) + x);
    return *this;
}

CircularInt& CircularInt::operator -=( int x) {
    this -> sum = check((this -> sum) - x);
    return *this;
}

CircularInt& CircularInt::operator *=( int x) {
    this-> sum =  check((this-> sum)*x);
     return *this;
}

CircularInt& CircularInt::operator /=( int x) {
this-> sum =  check((this-> sum)/x);
     return *this;
}

CircularInt& CircularInt::operator %=( int x) {
    this -> sum = (this -> sum % x) % this -> last;
    return *this;
}

// prefix increment operator
CircularInt& CircularInt::operator++() {
    this -> sum = check(this -> sum + 1);
    return *this;
}

// postfix increment operator
CircularInt& CircularInt::operator++(int x) {
    CircularInt temp{this-> first,this-> last};
    this-> sum = check(++this-> sum);
    return temp;
}

int CircularInt:: operator+( CircularInt& num) {
    return (this -> sum + num.sum)%this->last;
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
int operator-(int x, CircularInt& num) {
    int ans = (x-num.sum)%num.last;
    if(ans <= 0)
        ans += num.last;
    return ans;
}
int CircularInt:: operator-() {
    int ans=this->sum*(-1);
    while (ans<0){
        ans+=this->last;
    }
    return ans%this->last;
}
