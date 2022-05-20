#include <iostream>
#include <string>
#include <vector>
template<typename T> //generikus osztályok
struct S{
    S (T vv=0): val{vv}{} //alapból 0, míg meg nem változtatjuk
    T& get();
    S& operator=(const T&);
    void setVal(T val1){ 
        val = val1;
    }

private:
    T val;
};

template<typename T>
T& S<T>::get(){
    return val;
};


template<typename T>
S<T>& S<T>::operator=(const T& s){
    val =s;
    return val;
};

template<typename T>
std::ostream& operator<< (std::ostream& os,std::vector<T>& t ){
    os << "{ ";
    for (int i = 0; i < t.size(); ++i) {
        os << t.at(i) << " ";
    }
    os << " }";

    return os;

}

template<typename T>
std::istream& operator>> (std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}


template<typename T>
void read_val(T& v){ // istream, baloldal operator jobb oldal átadott ~40 sor
    std::cin >> v;
}

int main() {
    S<int> s; // típus S. 
    S<int> si {20}; //ugyan azt a struktúrát használja
    S<char> sc {'c'};
    S<double> sd {3.2};
    S<std::string> ss {"String"};
    S<std::vector<int>> svi {std::vector<int>{1,1,2,3,5,8}};

    //std::cout << "------int, double, string, {[szám],[szám],[...]}-------" << std::endl;
    std::cout << "S<int>: " << s.get() << std::endl;
    std::cout << "S<int>: " << si.get() << std::endl;
    std::cout << "S<char>: " << sc.get() << std::endl;
    std::cout << "S<double>: " << sd.get() << std::endl;
    std::cout << "S<string>: " << ss.get() << std::endl;
    //std::cout << "S<int>: " << svi.val << std::endl;

    for(S<int> a : svi.get()){ //int type
        std::cout << a.get() << ' ';
    }

    int ii;
    read_val(ii);
    S<int> si2 = {ii};

    double dd;
    read_val(dd);
    S<double> sd2 = {dd};

    std::string ss2;
    read_val(ss2);
    S<std::string> str = {ss2};

    
    std::cout << "S<int> : " << si2.get() << std::endl;
    std::cout << "S<double> : " << sd2.get() << std::endl;
    std::cout << "S<string> : " << str.get() << std::endl;

    std::vector<int> vint = {1,2,3,8,12,7,9};
    std::cout << vint << '\n';
    read_val(vint);
    S<std::vector<int>> svi2 = vint; //hozzáfűzés { }
    std::cout <<"S<vector<int>> read: " << svi2.get() << '\n';


    return 0;
}