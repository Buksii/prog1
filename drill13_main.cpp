#include <iostream>
#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
using namespace std;

using namespace Graph_lib;
int main() {

    try {
        const Point x {100,100};

        Simple_window win1 {Point{800, 800}, 800, 1000, "two lines"};
        win1.wait_for_button();

        int x_size = 800;
        int y_size = 800;
        int x_grid = 100;
        int y_grid = 100;

        Lines grid;
        for (int x = x_grid; x < x_size; x+=x_grid) {
            grid.add(Point{x, 0}, Point{x, y_size});
        }
        for (int y = y_grid; y < y_size; y+=y_grid) {
            grid.add(Point{0, y}, Point{x_size, y});
        }

        win1.attach(grid);
        win1.wait_for_button();
        grid.set_color(Color::red);
        //grid.set_style(Line_style{Line_style::dash, 2});
        win1.wait_for_button();

        Vector_ref<Rectangle> rectangles;
        for (int i = 0; i < x_size; i+=x_grid) {
            rectangles.push_back(new Rectangle(Point{i, i}, Point{i+x_grid, i+x_grid}));
            rectangles[rectangles.size()-1].set_fill_color(Color::red);
            rectangles[rectangles.size()-1].set_color(Color::invisible);
            win1.attach(rectangles[rectangles.size()-1]);
        }

        Image img (Point{0, 300}, "apple.jpeg");
        Image img1 (Point{300, 500}, "apple.jpeg");
        Image img2 (Point{500, 100}, "apple.jpeg");
        win1.attach(img);
        win1.attach(img1);
        win1.attach(img2);

        win1.wait_for_button();

        Image img_mv (Point{0, 0}, "bengalcat.jpg");
        img_mv.set_mask(Point{0, 0}, 100, 100);
        win1.attach(img_mv);
        win1.wait_for_button();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 7; j++) {
                img_mv.move(100, 0);
                win1.attach(img_mv);
                win1.wait_for_button();
                if (i>=1 && j==6){
                    img_mv.move(100, 0);
                    win1.attach(img_mv);
                    win1.wait_for_button();
                }
            }
            img_mv.move(-800, 100);
            win1.attach(img_mv);
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