#include "Header/Simple_window.h" //g++  bemeneti.cpp -o kimeneti //cd 
#include "Header/Graph.h" //g++ -w -Wall Graph.cpp Window.cpp GUI.cpp Simple_window.cpp 13drill.cpp `fltk-config --ldflags --use-images` -o a3.out 
#include "Header/GUI.h"
//#include "Lines_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
{
	try{

		Point t1{300,50};
		Simple_window win (t1,1000,800,"My Window");

		win.wait_for_button();

		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for (int i = 100; i <= x_size; i+= 100)
		{
			grid.add(Point(i, 0), Point(i, y_size));
			grid.add(Point(0, i), Point(x_size, i));
		}

		win.attach(grid);
		


		for (int y = 0; y < y_size; y += 100)
        {
            Rectangle *kocka = new Rectangle{Point{y, y}, Point{y + 100, y + 100}};            
            kocka->set_fill_color(Color::red);
            win.attach(*kocka);
        }

		win.wait_for_button();

	}

	catch (exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

	catch (...) {

		cerr << "exception" << endl;
		return 2;
	}

}

