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
CircularInt::CircularInt(const CircularInt& other){
      int first = other.first;
      int last = other.last;
      int sum =other.sum;
      this->first = first;
      this->last = last;
      this->sum = sum;
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

bool CircularInt::operator >(const CircularInt & num) const {return this -> sum > num.sum;}
bool CircularInt::operator >(const int x)const {return this -> sum > x;}

bool CircularInt::operator >=(const CircularInt & num) const {
        return this ->sum >= num.sum;
}
bool CircularInt::operator >=(const int x) const {
        return this ->sum >= x;
}

bool CircularInt::operator <(const CircularInt & num) const {
    return this ->sum < num.sum;
}
bool CircularInt::operator <(const int x)const {
    return this ->sum < x;
}

bool CircularInt::operator <=(const CircularInt & num) const {
    return this -> sum <= num.sum;
}
bool CircularInt::operator <=(const int x) const {
    return this -> sum <= x;
}

bool CircularInt:: operator ==(const CircularInt& num ) const{
    return this -> sum == num.sum;
}
bool CircularInt:: operator ==(const int x )const{
    return (this -> sum == x);
} 

bool CircularInt :: operator != (const CircularInt& num){
    return this -> sum != num.sum;
}
bool CircularInt :: operator != (const int x) const{
    return (this -> sum != x);
}

CircularInt& CircularInt :: operator=(const CircularInt& num){
    this->first = num.first;
    this->last = num.last;
    this->sum = num.sum;
    return *this;
}
CircularInt& CircularInt::operator=(int x) {
    this -> sum =x ;
    this -> sum = check(this -> sum);
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
    this-> sum *= x;
    this-> sum = check(this-> sum);
    return *this;
}
CircularInt& CircularInt::operator *=(CircularInt& num) {
    this -> sum *= num.sum;
    this-> sum = check(this-> sum);
    return *this;
}

CircularInt& CircularInt::operator++() {
    this -> sum = check(this -> sum + 1);
    return *this;
}
CircularInt CircularInt::operator++(int x) {
    CircularInt temp{this-> first,this-> last};
    this-> sum = check(this-> sum +1);
    return temp;
}

CircularInt& CircularInt::operator--() {
    this -> sum = check(this -> sum - 1);
    return *this;
}
CircularInt CircularInt::operator--(int x) {
    CircularInt temp{this-> first,this-> last};
    this-> sum = check(this-> sum-1);
    return temp;
}

CircularInt CircularInt :: operator+(int x){
    CircularInt temp{this-> first,this-> last};
    temp.sum = this -> sum;
    temp.sum =temp.check(temp.sum + x);
    return temp;
}
CircularInt operator+(int x, const CircularInt& num){
    CircularInt temp{num.first,num.last};
    temp.sum = num.sum;
    temp.sum = temp.check(temp.sum + x);
    return temp;
}
CircularInt CircularInt :: operator+(const CircularInt& num){
    CircularInt temp{this-> first, this-> last};
    temp.sum = this ->sum;
    temp.sum = temp.check(temp.sum + num.sum);
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
    temp.sum = check(temp.sum - x);
    return temp;
}
CircularInt operator-(int x, const CircularInt& num){
    CircularInt temp{num.first,num.last};
    temp.sum = num.sum;
    temp.sum = temp.check(x-temp.sum);
    return temp;
}
CircularInt CircularInt :: operator-(const CircularInt& num){
    CircularInt temp{this-> first, this-> last};
    temp.sum = check(this -> sum - num.sum);
    return temp;
}

CircularInt CircularInt :: operator*(int x){
    CircularInt temp{this-> first,this-> last};
    temp.sum *=x;
    temp.sum = temp.check(temp.sum);
    return temp;
}
CircularInt operator*(int x, const CircularInt& num){
    CircularInt temp{num.first,num.last};
    temp.sum = num.sum;
    temp.sum *=x;
    temp.sum = temp.check(temp.sum);
    return temp;
}
CircularInt CircularInt :: operator*(const CircularInt& num){
    CircularInt temp{this-> first, this-> last};
    temp.sum = this ->sum;
    temp.sum *= num.sum;
    temp.sum = temp.check(temp.sum);
    return temp;
}


CircularInt CircularInt::operator/ (int x)const{
      try{
        if(x == 0) {
          throw "Division by zero is forbidden!";
        }
        if(sum%x != 0) {
          double divi = (sum*1.0)/x;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << first << "," << last << "} such that " << divi << "*" << x << "=" << sum; 
          string msg = oss.str();
          throw msg;
        }
        CircularInt result(*this);
        result.sum /= x;
        result.sum = result.check(result.sum);
        return result;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
CircularInt& CircularInt::operator/=(int num){
               try{
        if(num == 0) {
          throw "Division by zero is forbidden!";
        }
        if(sum%num != 0) {
          double divi = (sum*1.0)/num;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << first << "," << last << "} such that " << divi << "*" << num << "=" << sum; 
          string msg = oss.str();
          throw msg;
        }
        this-> sum /= num;
        this -> sum = check(this-> sum);
        return *this;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
    
CircularInt& CircularInt::operator/=(CircularInt& other){
               try{
        if(other.sum == 0) {
          throw "Division by zero is forbidden!";
        }
        if(sum%other.sum != 0) {
          double divi = (sum*1.0)/other.sum;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << first << "," << last << "} such that " << divi << "*" << other.sum << "=" << sum; 
          string msg = oss.str();
          throw msg;
        }
        this-> sum /= other.sum;
        this-> sum = check(this-> sum);
        return *this;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
        
CircularInt CircularInt::operator/ (CircularInt& num)const{
      try{
        if(num.sum == 0) {
          throw "Division by zero is forbidden!";
        }
        if(sum % num.sum != 0) {
          double divi = (sum*1.0)/num.sum;
          ostringstream oss;
          oss << "There is no number " << divi << " in {" << first << "," << last << "} such that " << divi << "*" << num.sum << "=" << sum; 
          string msg = oss.str();
          throw msg;
        }
        CircularInt result(*this);
        result.sum /= num.sum;
        result.sum = result.check(result.sum);
        return result;
      }catch (const char* msg) {
        cerr << msg << endl;
      }
      return *this;
    }
