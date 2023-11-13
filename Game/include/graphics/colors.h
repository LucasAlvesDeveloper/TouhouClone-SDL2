#pragma once

struct Color
{
    int r, g, b, a = 255;
};

// Took the Colors from Raylib Cheatsheet, Find it in:
// https://www.raylib.com/cheatsheet/cheatsheet.html

namespace Colors
{
    const Color LIGHTGRAY = Color{200, 200, 200, 255}; // Light Gray
    const Color GRAY = Color{130, 130, 130, 255};      // Gray
    const Color DARKGRAY = Color{80, 80, 80, 255};     // Dark Gray
    const Color YELLOW = Color{253, 249, 0, 255};      // Yellow
    const Color GOLD = Color{255, 203, 0, 255};        // Gold
    const Color ORANGE = Color{255, 161, 0, 255};      // Orange
    const Color PINK = Color{255, 109, 194, 255};      // Pink
    const Color RED = Color{230, 41, 55, 255};         // Red
    const Color MAROON = Color{190, 33, 55, 255};      // Maroon
    const Color GREEN = Color{0, 228, 48, 255};        // Green
    const Color LIME = Color{0, 158, 47, 255};         // Lime
    const Color DARKGREEN = Color{0, 117, 44, 255};    // Dark Green
    const Color SKYBLUE = Color{102, 191, 255, 255};   // Sky Blue
    const Color BLUE = Color{0, 121, 241, 255};        // Blue
    const Color DARKBLUE = Color{0, 82, 172, 255};     // Dark Blue
    const Color PURPLE = Color{200, 122, 255, 255};    // Purple
    const Color VIOLET = Color{135, 60, 190, 255};     // Violet
    const Color DARKPURPLE = Color{112, 31, 126, 255}; // Dark Purple
    const Color BEIGE = Color{211, 176, 131, 255};     // Beige
    const Color BROWN = Color{127, 106, 79, 255};      // Brown
    const Color DARKBROWN = Color{76, 63, 47, 255};    // Dark Brown

    const Color WHITE = Color{255, 255, 255, 255};    // White
    const Color BLACK = Color{0, 0, 0, 255};          // Black
    const Color BLANK = Color{0, 0, 0, 0};            // Blank (Transparent)
    const Color MAGENTA = Color{255, 0, 255, 255};    // Magenta
    const Color RAYWHITE = Color{245, 245, 245, 255}; // My own White (raylib logo)

}