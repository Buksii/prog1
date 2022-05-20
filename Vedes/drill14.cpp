#include <iostream>
//virtuális: Felül lesz írva, valahogy viselkedni fog a függvény.
//absztrakt = legalább 1 fgv aminek nincs törzse  || =0
using namespace std;

class B1{

public:
    virtual void vf(){
        cout << "B1::vf()" << endl;
    }

    virtual void pvf() = 0;  //absztrakt osztály, mivel 0. Addig míg nem írjuk felül nem tudjuk használni
                             
    void f(){
        cout << "B1::f()" << endl;
    }

};

class D1 : public B1{ //örököl
public:
    virtual void vf(){
        cout << "D1::vf()" << endl;
    }
};

class D2 : public D1{ //örököl
public:
    void pvf(){
        cout << "D2::pvf()" << endl;
    }
};

class B2{ //absztrakt osztály
public:
    virtual void pvf() = 0;

};

class B21 : public B2{
public:
    string s;
    void pvf(){ //override
        cout << s << endl;
    }
};

class D22 : public B2{
public:
    int n; //publikus primitív változó
    void pvf(){
        cout << n << endl;
    }
};

void f(B2& b2){
    b2.pvf();

}

int main() {
    /*B1 b1;
    b1.f();
    b1.vf();*/

    /*D1 d1;
    d1.vf();*/

    /*B1& blr = d1;
    blr.vf();
    blr.f();*/

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    B21 b21;
    b21.s = "kiírás";
    b21.pvf();

    D22 d22;
    d22.n = 555;
    d22.pvf();

    f(b21);
    f(d22);


    return 0;
}