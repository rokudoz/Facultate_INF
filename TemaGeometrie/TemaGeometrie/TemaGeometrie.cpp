#include "graphics.h"

int main() {
    int x = 600;
    int y = 400;
    initwindow(x, y, "First Sample");

    // A
    int ax = 200;
    int ay = 130;
    circle(ax, ay, 2);

    // B
    int bx = 400;
    int by = 130;
    circle(bx, by, 2);

    // C
    int cx = 430;
    int cy = 195;
    circle(cx, cy, 2);

    // D
    int dx = 400;
    int dy = 300;
    circle(dx, dy, 2);

    line(ax, ay, bx, by);
    line(dx, dy, ax, ay);
    line(bx, by, cx, cy);
    line(dx, dy, cx, cy);
    for (int i = 1; i <= 1; i++) {
        setlinestyle(i, 0, 1);
        line(dx, dy, bx, by);
    }


    while (!kbhit()) {
        delay(200);
    }
    return 0;
}
