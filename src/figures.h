#ifndef SHAPESORTER_FIGURES
#define SHAPESORTER_FIGURES 1

void coordinate_axes(int len);
void draw_main_cube(float size);
void draw_falling_figure(int id);

// draw background figures just to fill the void
void draw_background_figures();
// draw background rectangle which will be filled with textures
void background(float w, float h);

#endif /* ifndef SHAPESORTER_FIGURES */
