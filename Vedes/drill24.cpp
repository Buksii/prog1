#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Header/Matrix.h"
#include "Header/MatrixIO.h"

//Funktor: függvény, ami osztályként viselkedik

using namespace std;

using Numeric_lib::Matrix;
using Numeric_lib::Index;

void sqrt_valid(int number){
    if (number > 0) {
        cout << sqrt(number) << '\n';
    }
    else {
        cout << "Not a number\n";
    }
}

int main() {
    try {
        cout << "sizeof:\n";
        cout << "char\t" << sizeof(char) << '\n'; //hány bájtot foglal
        cout << "short\t" << sizeof(short) << '\n';
        cout << "int\t" << sizeof(int) << '\n';
        cout << "long\t" << sizeof(long) << '\n';
        cout << "float\t" << sizeof(float) << '\n';
        cout << "double\t" << sizeof(double) << '\n';
        cout << "int*\t" << sizeof(int*) << '\n';
        cout << "double*\t" << sizeof(double*) << '\n';

        cout << "\nMatrix sizes:\n";
        Matrix<int> a(10);
        Matrix<int> b(100);
        Matrix<double> c(10);
        Matrix<int, 2> d(10, 10);
        Matrix<int, 3> e(10, 10, 10);

        cout << "1d int, 10 elem\t\t\t" << sizeof(a) << '\n';
        cout << "1d int, 100 elem\t\t" << sizeof(b) << '\n';
        cout << "1d double, 10 elem\t\t" << sizeof(c) << '\n';
        cout << "2d int, 10*10 elem\t\t" << sizeof(d) << '\n';
        cout << "3d int, 10*10*10 elem\t\t" << sizeof(e) << '\n';

        /*int number = 0;
        for (int i = 0; i < 10; i++) {
            cin >> number;
            sqrt_valid(number);
        }*/

        //Matrix<double> m2 (10);
       /* double d2;
        for (int i = 0; i < m2.size(); ++i) {
        }*/

        //cout << "Matrix:\n" << m2 << '\n';
        double d1;
        double d2;
        cin >> d1 >> d2;
        Matrix<int, 2> multi_table(d1, d2); //int, dimenzió

        for (int i = 0; i < multi_table.dim1(); ++i) { //szorzótábla 
            for (int j = 0; j < multi_table.dim2(); ++j) {
                multi_table(i, j) = (i+1) * (j+1); //i j-edik sorába beilleszti az i+1 * j+1 -et
            }
        }
        for (int i = 0; i < multi_table.dim1(); ++i) { //kiírás sor
            for (int j = 0; j <multi_table.dim2(); j++) { //oszlop
                cout << multi_table(i, j) << '\t';
            }
            cout << endl;
        }

        Matrix<complex<double>> mcomp(10);
        cout << "Enter 10 complex numbers (Re, Im): ";
        complex<double> comp;
        for (int i = 0; i < 10; ++i) {
            cin >> comp;
            if(!cin) throw runtime_error("Problem reading complex number!");
            mcomp[i] = comp;
        }
        complex<double> sum; //complex number calc doesnt work!
        for (Index i = 0; i < mcomp.size(); ++i) {
            sum+= mcomp[i];
        }
        cout << "Sum: " << sum << '\n';

    } catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    catch (...){
        cerr << "Exception!\n";
    }
    return 0;
}

