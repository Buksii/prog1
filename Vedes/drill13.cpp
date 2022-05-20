#include <iostream>
#include "Header/Graph.h"
#include "Header/Simple_window.h"
using namespace std;
//    clang++ -std=c++11 drill13.cpp Header/Graph.cpp Header/Window.cpp Header/GUI.cpp Header/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
using namespace Graph_lib;
int main() {

    try {
        const Point x {100,100};

        Simple_window win1 {Point{800, 800}, 800, 1000, "two lines"};
        win1.wait_for_button();

        int x_size = 800;
        int y_size = 800;
        int x_grid = 100; // vonalkák
        int y_grid = 100;

        Lines grid;
        for (int x = x_grid; x < x_size; x+=x_grid) {
            grid.add(Point{x, 0}, Point{x, y_size}); //honnan, hova
        }
        for (int y = y_grid; y < y_size; y+=y_grid) {
            grid.add(Point{0, y}, Point{x_size, y}); //same
        }

        win1.attach(grid); // attach grid
        win1.wait_for_button();
        grid.set_color(Color::red);
        //grid.set_style(Line_style{Line_style::dash, 2});
        win1.wait_for_button();

        Vector_ref<Rectangle> rectangles; //referencia vektor
        for (int i = 0; i < x_size; i+=x_grid) {

            rectangles.push_back(new Rectangle(Point{i, i}, Point{i+x_grid, i+x_grid}));  //x_grid 100
            rectangles[rectangles.size()-1].set_fill_color(Color::red);
            rectangles[rectangles.size()-1].set_color(Color::invisible);
            win1.attach(rectangles[rectangles.size()-1]);
        }

        Image img (Point{0, 300}, "kepek/kep.jpeg");
        Image img1 (Point{300, 500}, "kepek/kep.jpeg");
        Image img2 (Point{500, 100}, "kepek/kep.jpeg");
        win1.attach(img);
        win1.attach(img1);
        win1.attach(img2);

        win1.wait_for_button();

        Image mozgatas (Point{0, 0}, "kepek/kep.jpeg"); //bal fent 
        mozgatas.set_mask(Point{0, 0}, 100, 100); //maszkolás 100x100-ra
        win1.attach(mozgatas);
        win1.wait_for_button();
        for (int i = 0; i < 8; i++) { 
            for (int j = 0; j < 7; j++) {
                mozgatas.move(100, 0);
                win1.attach(mozgatas);
                win1.wait_for_button();
                if (i>=1 && j==6){ //elsőtől az utolsó négyzetrácsig menjen kókány
                    mozgatas.move(100, 0); //visszatolja balra 1-el 
                    win1.attach(mozgatas);
                    win1.wait_for_button();
                }
            }
            mozgatas.move(-800, 100);
            win1.attach(mozgatas);
        }


    }
    catch(exception& e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "error\n";
        return 2;
    }

    return 0;
}