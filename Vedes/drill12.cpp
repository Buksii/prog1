#include <iostream>
#include "Header/Graph.h"
#include "Header/Simple_window.h"
#include <string>
//    clang++ -std=c++11 drill12.cpp Header/Graph.cpp Header/Window.cpp Header/GUI.cpp Header/Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`

using namespace std;

int main() {


    try {
        using namespace Graph_lib;

        Point t1 {100, 100};

        Simple_window win {t1, 600, 400, "My Window"};
        win.wait_for_button();

        Axis xa {Axis::x, Point{20, 300}, 200, 10, "x axis"};
        win.attach(xa);
        win.set_label("X Axis");
        win.wait_for_button();

        Axis ya {Axis::y, Point{20, 300}, 280, 10, "Y axis"};
        ya.set_color(Color::cyan);
        ya.label.set_color(Color::dark_red);
        win.attach(ya);

        win.set_label("Y Axis");
        win.wait_for_button();

        Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
        win.attach(sine);

        win.set_label("Sine");
        win.wait_for_button();

        sine.set_color(Color::blue);

        Polygon poly;
        poly.add(Point{300, 200});
        poly.add(Point{350, 100});
        poly.add(Point{400, 200});

        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);
        win.attach(poly);
        win.set_label("Poly");
        win.wait_for_button();

        Rectangle r {Point{200, 200}, 100, 50};
        win.attach(r);
        win.set_label("Rectangle time!");
        win.wait_for_button();

        Closed_polyline poly_rect;

        poly_rect.add(Point{100, 50});
        poly_rect.add(Point{200, 50});
        poly_rect.add(Point{200, 100});
        poly_rect.add(Point{100, 100});
        poly_rect.add(Point{50, 75});
        win.attach(poly_rect);
        win.wait_for_button();

        //Line style and fill color determination
        r.set_fill_color(Color::yellow);
        poly.set_style(Line_style(Line_style::dash, 4));
        poly_rect.set_style(Line_style(Line_style::dash, 2));
        poly_rect.set_fill_color(Color::green);
        win.set_label("Color time!");
        win.wait_for_button();

        //Text writing
        Text t {Point{150, 150}, "Hello Graphical world"};
        t.set_font(Font::times_bold);
        t.set_font_size(20);
        win.set_label("Text time!!");
        win.attach(t);
        win.wait_for_button();

        //IMAGES
        Image ii (Point{100, 50}, "Header/badge.jpg");
        win.attach(ii);
        win.set_label("Image time!!");
        win.wait_for_button();

        //img moving
        ii.move(100, 200);
        win.set_label("We are moving an image, this isn't joke!!");
        win.wait_for_button();

        Circle c {Point{100, 200}, 50};
        Ellipse e {Point{100, 200}, 75, 25};
        e.set_color(Color::dark_red);
        Mark m {Point{100, 200}, 'x'};

        ostringstream oss;
        oss << "Screen size: " << x_max() << "*" << y_max() << "; windows size: " << win.x_max() << "*" << win.y_max();
        Text size {Point{100, 20}, oss.str()};

        Image cal {Point{600, 225}, "kepek/kep.jpeg"};
        ///cal.set_mask(Point{40, 40}, 200, 150);
        win.attach(c);
        win.attach(e);
        win.attach(m);
        win.attach(size);
        win.attach(cal);
        win.label("Circle, ellipse, new image time!");
        win.wait_for_button();


    }catch(exception &e){
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }catch (...){
        cerr << "error\n";
        return 2;
    }
    return 0;
}
