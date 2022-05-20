#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm> //std::find 

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
Iter2 o_copy(Iter1 f1, Iter1 e1, Iter2 f2){
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
    copy(arr, arr + size, arrayOfNumbers.begin()); //beépített copy átmásoljk a tömböt, pointereket másol technicly || ugyan az a memória cím
    vector<int> vectorOfNumbers(size); //size méretű
    copy(arr, arr+size, vectorOfNumbers.begin()); //same sht
    list<int> listOfNumbers(size); // -||-
    copy(arr, arr+size, listOfNumbers.begin());

    array<int, size> i2 = arrayOfNumbers; //nem másolunk, hanem egyenlővé tesszük || másik memória cím
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


    o_copy(i2.begin(), i2.end(), vi2.begin());
    o_copy(li2.begin(), li2.end(), i2.begin());

    print(i2);
    print(vi2);
    print(li2);

    vector<int>::iterator vit;
    vit = std::find(vi2.begin(), vi2.end(), 6); // find x at hanyadik érték

    if (vit!=vi2.end()) 
    {   
        cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
    } else {
        cout << "Not found" << endl;
    }
    

    return 0;
}