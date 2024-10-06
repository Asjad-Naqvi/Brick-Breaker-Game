#include "level2.h"

level2::level2() {
    // Initialize your variables here if needed
}

void level2::display() {
    // Adjusting starting position to ensure the diamond is centered
    int startX = x2 - (size * 4); // size * 4 is half the width of the diamond
    int startY = y2 - (size * 4); // size * 4 is half the height of the diamond

    for (int i = 0; i < size * 2 + 1; i++) {
        for (int j = 0; j < size * 2 + 1; j++) {
            // Condition to check if the current position is within the diamond shape
            if (abs(i - size) + abs(j - size) <= size) {
                // Calculating actual position of the square
                int posX = startX + j * size;
                int posY = startY + i * size;
                // Drawing the square at calculated position
                DrawSquare(posX, posY, size, colors[WHITE]);
            }
        }
    }
}
