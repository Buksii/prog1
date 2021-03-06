#include <iostream>
#include <vector>
#include <string> //19 drill 482 oldal

using namespace std;

template<typename T>
struct S{
    S(T vv = 0) : val{vv} {}

    T& get(); //getter
    const T& get() const;
    
    void set(T new_t){ //setter
        val = new_t;
    }
    S<T>& operator = (const T& s);

    private:
            T val;

    
};
template<typename T>
S<T>& S<T>::operator = (const T& s){
    val = s;
    return *this;
}

template<typename T>
T& S<T>::get(){
    return val;
}

template<typename T>
const T& S<T>::get() const {
    return val;
}

template<typename T> void read_val(T& v ){
    cin >> v;

}

//--------------- ostream istream --------------

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "(";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << (i< v.size() -1 ? ", ": " ");
    }
    os << "}\n";
    return os;
    
    //return os;
    //cout << "nesze" << os << endl;
}
template <typename T>
istream& operator >> (istream& is, vector<T>& v)
{
    char ch =0 ;
    is >> ch;
    if (ch!= '{'){
        is.unget();
        return is;
    }
    for (T val: is >> val)
    {
        v.push_back(val);
        is >> ch;
        if (ch != ',')
        {
            break;
        }
        return is;
    }
    
    {
        /* code */
    }
    
}
 

int main(){
    S<int> s;
    S<int> si {37};
    S<char> sc {'c'};
    S<double> sd {10.2};
    S<std::string> ss {"Hello"};
    S<std::vector<int>> svi {std::vector<int> {1,2,3,4,5,7}};

    cout <<"S<int> : " << s.get() <<endl
         <<"S<int> : " << si.get() <<endl
         <<"S<char> : " << sc.get() <<endl
         <<"S<double> : " << sd.get() <<endl
         <<"S<string> : " << ss.get() <<endl;
         //<<"S<vector<int>> : " << si.get() <<endl
         cout << "S<vector<int>> :" ;

         for(auto& a : svi.get()){
             cout << a << ' ';
             
         }  
         cout << endl;

        sc.set('s');


        cout << "S<double> : " << sd.get()<<endl;
        
        int ii;
        read_val(ii);
        S<int> si2 {ii};

        char cc;
        read_val(cc);
        S<char> sc2 {cc};

        double dd;
        read_val(dd);
        S<double> sd2 {dd};
        
        cout 
         <<"S<int> : " << si2.get() <<endl
         <<"S<char> : " << sc2.get() <<endl
         <<"S<double> : " << sd2.get() <<endl;

        cout << "S<vector<int>> : (format: {val, val, val}";
        vector <int> vi2;
        read_val(vi2);
        S<vector<int>> svi2 {vi2};

        cout <<"S<vector<int>> sv2: " <<svi2.get() <<endl;

}