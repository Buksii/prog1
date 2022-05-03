#include <iostream>

template<typename T>
class A{
public:
    A() { }
    virtual void abs(T anything) = 0;

};

template <typename T>
class B: public A<T>{
public:
    B() {}
    void abs(T anything){
        std::cout << "This is the content of the B class: " << anything << std::endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    B<std::string> *stuff = new B<std::string>();
    stuff->abs("20");


    return 0;
}
