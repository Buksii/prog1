#include <iostream>
#include <stdexcept>
#include <string>
#include <numeric>
#include <map>

template<typename K, typename V>
void print(const std::map<K, V>& m){
    for (std::pair<K,V> i : m ){
        std::cout << i.first << " " << i.second << std::endl;

    }
    std::cout << "\n";
}

void read_map(std::map<std::string, int>& m){
    std::string s;
    int i = 0;
    while (m.size()<10){
        std::cin >> s >> i;
        m.insert(std::make_pair(s, i)); //nem ír felül
        //m[s] = i; felülír
    }

}
void sumOfElements(std::map<std::string, int>& m){
    int sum = 0;
    for (std::pair<std::string, int> i : m){
        sum+=i.second;
    }
    std::cout << sum << std::endl;
}

int main() {
    try {
        std::map<std::string, int> msi;
        msi["a"] = 2;
        msi["b"] = 3;
        msi["abc"] = 4;
        msi["cd"] = 5;
        msi["qwerty"] = 6;
        msi["po"] = 32;
        msi["xy"] = 300;
        msi["fd"] = 123;
        msi["ks"] = 345;
        msi["xz"] = 423;
        print(msi);

        msi.erase("a");
        print(msi);

        std::cout << "Write in 10 key value pairs" << std::endl;
        read_map(msi);
        print(msi);

        sumOfElements(msi);

        std::map<int, std::string> mis;
        for (std::pair<std::string, int> i: msi) {
            mis[i.second] = i.first;
        }
        std::cout << "Mis map: " << std::endl;
        print(mis);



    }catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }catch (...){
        std::cerr << "Unknown exception" << '\n';
        return 2;
    }
    return 0;
}