#include <iostream>
using namespace std;

class Rat{

private:
    int n;
    int d;
public:
    // constructors
    // default constructor
    Rat(){
        n=0;
        d=1;
    }
    // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
    }
    // conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }
    //accessor functions (usually called get() and set(...) ) int getN(){ return n;}
    int getD(){
        return d;
    }
    void setN(int i){
        n=i;
    }
    void setD(int i){
        d=i;
    }
    //arithmetic operators
    //add
    Rat operator+(Rat r){
        Rat t;
        t.n = n*r.d+d*r.n;
        t.d = d*r.d;
        return t;
    }
    //subtract
    Rat operator-(Rat r){
        Rat t;
        t.n = n*r.d-d*r.n;
        t.d = d*r.d;
        return t;
    }
    //multiply
    Rat operator*(Rat r){
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        return t;
    }
    //divide
    Rat operator/(Rat r){
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        return t;
    }

    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

int gcd(int n, int d){
    if (d==0)return n;
    return gcd(d,n%d);
}

Rat reduce(int &i, int &j){
    for(int a = i; a > 0; a--){
        if(i % a == 0 && j % a == 0){
            i = i / a;
            j = j / a;
            break;
        }
    }
    return Rat(i,j);
}
ostream& operator<<(ostream& os, Rat r){
    if(r.n >= r.d){
        if(r.n % r.d == 0){
            os << r.n / r.d << endl;
        } else {
            int x = gcd(r.n%r.d,r.d);
            os << r.n / r.d << " " << (r.n%r.d) / x << " / " << (r.d) / x << endl;
        }
    } else if(r.n == 0){
        os << r.n << endl;
    } else {
        int x = gcd(r.n%r.d,r.d);
        os << r.n / x << " / " << r.d/ x << endl;
    }

    return os;
}
// operator>>() is NOT a member function but since it was declared a friend of Rat // it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
    reduce(r.n, r.d);
    return is;
}

int main(){
    Rat r1(5, 2), r2(2, 3);

    cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;

   r1 = r2;
   r2 = r1 * r2;

   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;

   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;

   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
    return 0;
}
