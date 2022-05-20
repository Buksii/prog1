#include <iostream>
#include <vector>

using namespace std;
 //saját adatípus

struct Person{
private:
    //string name;
    string firstname;
    string lastname;
    int age;
public:
    Person(){

    }
    Person(string firstname, string lastname, int age){ //konstruktor
        if (age <0 || age >= 150){
            throw runtime_error{"invalid age"};
        }
        char arr[] = { ':', ';', '[', ']', '*', '&', '^', '$', '#', '@', '!', '\"', '\''};
        for (int i = 0; i < sizeof(arr); i++) {
            if ((firstname.find(arr[i]) < firstname.length()) || (lastname.find(arr[i]) < lastname.length())){
                throw runtime_error{"Invalid char"};
            }
        }
        //this->name = name;
        this->firstname = firstname; //!!!!!!!
        this->lastname = lastname;
        this->age = age;
    }

    const string getFirstName() const { //getterek
        return firstname;
    }
    const string getLastName() const{
        return lastname;
    }

    int getAge() const {
        return age;
    }

};

ostream& operator<< (ostream& os, const Person& p){
    return os << p.getFirstName() << " " <<p.getLastName() << " " << p.getAge();
}

istream& operator>> (istream& is, Person& p){
    string n;
    string n2;
    int a;
    is >> n >> n2 >> a ; //operatorba beletöltöm a fnamet lnamet és aget
    p = Person(n, n2, a);
    return is;
}

int main() {
    Person prs = Person("Goofy","Mr", 63);
    cout << prs.getFirstName() <<" "<< prs.getLastName() << " "<< prs.getAge() << endl; //getterek meghívva couttal
    Person p;
    Person p2;

    cin >> p; //mintha fgvt hívnánk meg [50] sor
    cin >> p2; 
    cout << p << endl << p2 << endl;
    cout << prs << endl;

    vector<Person> vec;
    while (cin >> p){
        if (p.getFirstName()=="end" || p.getLastName() =="end"){
            cout << "Itt jártam!" << endl;
            break;
        }else{
        vec.push_back(p);
        }
    }

    for(Person p4 : vec){
        cout << p4 << endl;
    }

    return 0;
}