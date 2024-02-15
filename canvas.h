#ifndef CANVAS_H
#define CANVAS_H

//This struct has the number of rows, the number of columns, and the characters in the canvas
typedef struct {
    int num_rows;
    int num_cols;
    char **data; 
} Canvas;

void empty_canvas(Canvas *canvas, int num_rows, int num_cols);
void freeCanvas(Canvas *canvas);
void printCanvas(const Canvas *canvas);

#endif