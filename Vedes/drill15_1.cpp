#include <iostream>
#include "Header/Simple_window.h"
#include "Header/Graph.h"
#include "Header/Window.h"

//clang++ -std=c++11 drill15_1.cpp Header/Graph.cpp Header/Window.cpp Header/GUI.cpp Header/Simple_window.cpp -o drill15_1 `fltk-config --ldflags --use-images`

using namespace std;

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
    try
    {
        const Point p{300, 300};
        Simple_window window{Point{100, 100}, 600, 600, "Function Graphs"};

        Axis x{Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
        Axis y{Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};

        x.set_color(Color::red);
        y.set_color(Color::red);

        window.attach(x);
        window.attach(y);

        window.wait_for_button();

        const int max_num = 11;
        const int min_num = -11;
        const int x_scale = 20;
        const int y_scale = 20;
        const int points = 400;

        Function f1{one, min_num, max_num, p, points, x_scale, y_scale};

        Function f2{slope, min_num, max_num, p, points, x_scale, y_scale};
        Text f2_label{Point{max_num + 50, f2.point(0).y - 10}, "x/2"};

        Function f3{square, min_num, max_num, p, points, x_scale, y_scale};

        Function f4{cos, min_num, max_num, p, points, x_scale, y_scale};
        f4.set_color(Color::blue);

        Function f5{sloping_cos, min_num, max_num, p, points, x_scale, y_scale};

        window.attach(f1);
        window.attach(f2);
        window.attach(f2_label);
        window.attach(f3);
        window.attach(f4);
        window.attach(f5);

        window.wait_for_button();
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << endl;
        keep_window_open();
    }
    catch (...)
    {
        cerr << "exception\n";
        keep_window_open();
    }
    return 0;
}