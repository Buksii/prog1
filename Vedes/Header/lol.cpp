#include "Simple_window.h" //g++  bemeneti.cpp -o kimeneti
#include "GUI.h" //g++ -w -Wall Graph.cpp Window.cpp GUI.cpp Simple_window.cpp 12drill.cpp `fltk-config --ldflags --use-images` -o a2.out 


#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
{

	try {
		Point t1 {100,100};

		Simple_window win {t1, 640, 400, "My window"};

		win.wait_for_button();

		Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"}; //x axis kirajz
		win.attach(xa);
		win.set_label("Axis");
		win.wait_for_button();

		Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"}; //y axis kirajz
		ya.set_color(Color::cyan);
		win.attach(ya);
		win.set_label("y axis");
		win.wait_for_button();

		Function sine {sin, 0, 100, Point{20,150}, 1000, 50, 50}; //sinus függvény kirajz
		win.attach(sine);
		win.set_label("Sine function");
		win.wait_for_button();

		Polygon poly; //triangle kirajz
		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		poly.set_color(Color::red);
		poly.set_style(Line_style::dash);
		win.attach(poly);
		win.set_label("Draw polygon");
		win.wait_for_button();

		Rectangle r {Point{200,200}, 100, 50}; //rectangle kirajz 1)
		win.attach(r);

		Closed_polyline poly_rect; //rectangle kirajz 2)
		poly_rect.add(Point{100, 50});
		poly_rect.add(Point{200, 50});
		poly_rect.add(Point{200, 100});
		poly_rect.add(Point{50, 75});

		win.set_label("Draw rectangle");
		win.wait_for_button();


	} catch (exception& e) {

		cerr << "exception: " <<e.what()<< '\n';
		return 1;

	} catch (...){

		cerr << "error\n";
		return 2;
	}


}