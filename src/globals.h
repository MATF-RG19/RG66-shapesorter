#ifndef SHAPESORTER_GLOBALS
#define SHAPESORTER_GLOBALS 2

#include <vector>

// enumaration of main cube sides for clarity
// We are using vector iterator to keep pointer on side that's normal to positive Oy
enum Cube_side { blue_square = 0, triangle = 1, green_square = 2, circle = 3};
extern std::vector<Cube_side> cube_sides;
extern std::vector<Cube_side>::const_iterator iter;

// True if main cube is rotating
extern bool rotation_in_progress;

// Total rotation angle
extern float angle;

// rotation_cycle_angle <= [0, 90]
// Something like a flag for rotation of the main cube. 
// For every keypress, it starts as zero and goes to 90. 
// When it reaches >= 90, rotation for that keypress stops.
// angle is simultaneously incremented
extern float rotation_cycle_angle;

// True if player started the game
extern bool animation_ongoing;

// Position of randomly spawned figure on one of Ox/Oy axes
extern float falling_figure_position;

// ID of current figure thats approaching (0, 0, 0)
extern int current_falling_figure;

// zameniti MACROIMA kasnije
extern int main_cube_rotation_axis;

// Flag that tells on which axis(Ox or Oy) will new falling figure spawn
extern int spawn_axis;

// Translation coefs for Ox, Oy
extern float tx;
extern float ty;



#endif /* ifndef SHAPESORTER_GLOBALS */
