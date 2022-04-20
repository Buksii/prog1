#include <iostream>
#include <vector>
#include <list>
#include <array>

using namespace std;

template<typename C>
void print(const C& c){
    for (auto elem : c) {
        cout << elem << " ";
    }
    cout << endl;
}

template<typename C>
void inc(C& c, int n){
    for (auto& elem : c) {
        elem = elem+n;
    }
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    for(Iter1 p = f1; p!=e1; ++p){
        *f2++ = *p;
    }
    return f2;
}


int main() {
    constexpr int size = 10;

    int arr[size];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }
    array<int, size> arrayOfNumbers;
    copy(arr, arr + size, arrayOfNumbers.begin());
    vector<int> vectorOfNumbers(size);
    copy(arr, arr+size, vectorOfNumbers.begin());
    list<int> listOfNumbers(size);
    copy(arr, arr+size, listOfNumbers.begin());

    array<int, size> i2 = arrayOfNumbers;
    vector<int> vi2 = vectorOfNumbers;
    list<int> li2 = listOfNumbers;
    print(i2);
    print(vi2);
    print(li2);
    inc(i2, 2);
    inc(vi2, 3);
    inc(li2, 5);
    print(i2);
    print(vi2);
    print(li2);


    orai_copy(i2.begin(), i2.end(), vi2.begin());
    orai_copy(li2.begin(), li2.end(), i2.begin());

    print(i2);
    print(vi2);
    print(li2);

    std:vector<int>::iterator vit;
    vit = std::find(vi2.begin(), vi2.end(), 2);

    if (vit!=vi2.end())
    {   
        cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
    } else {
        std::cout << "Not found" << endl;
    }
    

    return 0;
}