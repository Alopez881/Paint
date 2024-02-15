#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canvas.h"
//This file makes and frees the canvas painting and editing

//This function makes space for the canvas
void empty_canvas(Canvas *canvas, int num_rows, int num_cols) {
    //This makes room for the canvas row 
    canvas->num_rows = num_rows;
    canvas->num_cols = num_cols;
    canvas->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        //This makes room for the canvas row 
        canvas->data[i] = (char *)malloc(num_cols * sizeof(char));
        for (int j = 0; j < num_cols; j++) {
            //This fills the canvas with a blank space character
            canvas->data[i][j] = '*'; 
        }
    }
}
//This function frees up the canvas space
void freeCanvas(Canvas *canvas) {
    if (canvas->data != NULL) {
        //This frees up the canvas space
        for (int i = 0; i < canvas->num_rows; i++) {
            free(canvas->data[i]);
        }
        free(canvas->data);
        canvas->data = NULL;
    }
    canvas->num_rows = 0;
    canvas->num_cols = 0;
}
//This shows the canvas
void printCanvas(const Canvas *canvas) {
    //This goes row by row
    for (int row = canvas->num_rows - 1; row >= 0; row--) {
        //This shows the row numbers
        printf("%d ", row);
        //This goes by column
        for (int col = 0; col < canvas->num_cols; col++) {
            // Print the character at the current row and column
            printf("%c ", canvas->data[row][col]);
        }
        printf("\n");
    }
    //This shows the column numbers
    printf("  ");
    for (int col = 0; col < canvas->num_cols; col++) {
        printf("%d ", col);
    }
    printf("\n");
}

