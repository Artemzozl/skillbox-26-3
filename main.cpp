#include <iostream>

class Windows{
private:
    int x =0, y = 0, w = 0, h = 0;

public:
    void setWindows(int inX, int inY, int inW, int inH){
        x = inX;
        y = inY;
        w = inW;
        h = inH;
    }
    void moveWindow (int dInX, int dInY){
        int dX = 0, dY = 0;
        x += dInX;
        y += dInY;
        //setWindows(dX, dY, 0, 0);
        std::cout << "Window moved to (" << x << ", " << y << ")" << std::endl;
    }

    void resizeWindow(int dInW, int dInH){
        int dW = 0, dH = 0;
        if (dInW > 0 && dInH > 0) {
            w = dInW;
            h = dInH;
          //  setWindows(0,0,dW,dH);
            std::cout << "Window resized to " << w << "x" << h << std::endl;
        } else {
            std::cout << "Invalid size. Window size remains unchanged." << std::endl;
        }
    }

    void displayWindow () const {
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 80; ++j) {
                if (j >= x && j < x + w && i >= y && i < y + h) {
                    std::cout << "1";
                } else {
                    std::cout << "0";
                }
            }
            std::cout << std::endl;
        }
    }


};


int main() {
    int cordX, cordY, cordW, cordH;
    std::string command;
    Windows windClass;
    windClass.setWindows(10, 20, 30, 30);
    do {
        std::cout << "Enter command (move, resize, display, close): ";
        std::cin >> command;

        if (command == "move") {
            std::cout << "Enter displacement vector (dx dy): ";
            std::cin >> cordX >> cordY;
            windClass.moveWindow(cordX, cordY);
        } else if (command == "resize") {
            std::cout << "Enter new window size (width height): ";
            std::cin >> cordW >> cordH;
            windClass.resizeWindow(cordW, cordH);
        } else if (command == "display") {
            windClass.displayWindow();
        }
    } while (command != "close");









    return 0;
}