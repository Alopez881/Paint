// commands.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "paint.h"
#include "canvas.h"
//This file does the command that the user wanted

//This function shows the user the commands if they ask for help Function to display help information
void print_help(const Canvas *canvas) {
    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
    printCanvas(canvas);
}

//This function check that a given coordinate is in the canvas
int is_valid_coord(const Canvas *canvas, int row, int col) {
    return (row >= 0 && row < canvas->num_rows && col >= 0 && col < canvas->num_cols);
}

//This function writes the lines given coordinates by the user or tells them that the coordinates are not a line
void write_comm(Canvas *canvas, int start_row, int start_col, int end_row, int end_col) {

    // Handle different types of lines (horizontal, vertical, diagonal) and intersections.
    // Update the canvas data structure accordingly.

    //This checks if the coordinate is just a single point
    if (start_row == end_row && start_col == end_col) {
        // If the coordinates are the same, it's a single cell line, draw it with "-"
        if (is_valid_coord(canvas, start_row, start_col)) {
            canvas->data[start_row][start_col] = '-';
        } else {
            printf("Invalid coordinates for a single-cell line.\n");
        }
    } 
    //This checks if the coordinates make a horizonatal line
    else if (start_row == end_row) {
        if (is_valid_coord(canvas, start_row, start_col) && is_valid_coord(canvas, end_row, end_col)) {
            int min_col = (start_col < end_col) ? start_col : end_col;
            int max_col = (start_col > end_col) ? start_col : end_col;
            //This writes the line
            for (int col = min_col; col <= max_col; col++) {
                //This checks if the coordinate passes over another line that it's not coincident
                if (canvas->data[start_row][col] == '|' || canvas->data[start_row][col] == '/' || canvas->data[start_row][col] == '\\' || canvas->data[start_row][col] == '+') {
                    canvas->data[start_row][col] = '+';
                    //if the do overlape, continue with the normal line
                } else {
                    canvas->data[start_row][col] = '-';
                }
            }
        } else {
            printf("Invalid coordinates for a horizontal line.\n");
        }
    } 
    //This checks if the coordinates make a vertical line
    else if (start_col == end_col) {
        if (is_valid_coord(canvas, start_row, start_col) && is_valid_coord(canvas, end_row, end_col)) {
            int min_row = (start_row < end_row) ? start_row : end_row;
            int max_row = (start_row > end_row) ? start_row : end_row;
            //This writes the line
            for (int row = min_row; row <= max_row; row++) {
                if (canvas->data[row][start_col] == '/' || canvas->data[row][start_col] == '-' || canvas->data[row][start_col] == '\\' || canvas->data[row][start_col] == '+') {
                    canvas->data[row][start_col] = '+';
                    //if the do overlape, continue with the normal line
                } else {
                    canvas->data[row][start_col] = '|';
                }
            }
        } else {
            printf("Invalid coordinates for a vertical line.\n");
        }
    } 
    //This checks if the coordinates make a left diagonal line
    else if (start_row > end_row && start_col < end_col) {

        if (is_valid_coord(canvas, start_row, start_col) && is_valid_coord(canvas, end_row, end_col)) {
            //This writes the line
            for (int row = start_row, col = start_col; row >= end_row && col <= end_col; row--, col++) {
                if (canvas->data[row][col] == '/' || canvas->data[row][col] == '|' || canvas->data[row][col] == '-' || canvas->data[row][col] == '+') {
                    canvas->data[row][col] = '+';
                    //if the do overlape, continue with the normal line
                } else {
                    canvas->data[row][col] = '\\';
                }
            }
        } else {
            printf("Invalid coordinates for a left diagonal line.\n");
      
        }
    } 
    else if (start_row < end_row && start_col > end_col) {

        if (is_valid_coord(canvas, start_row, start_col) && is_valid_coord(canvas, end_row, end_col)) {
            //This writes the line
            for (int row = end_row, col = end_col; row >= start_row && col <= start_col; row--, col++) {
                if (canvas->data[row][col] == '/' || canvas->data[row][col] == '|' || canvas->data[row][col] == '-' || canvas->data[row][col] == '+') {
                    canvas->data[row][col] = '+';
                    //if the do overlape, continue with the normal line
                } else {
                    canvas->data[row][col] = '\\';
                }
            }
        } else {
            printf("Invalid coordinates for a left diagonal line.\n");
      
        }
    } 
    //This checks if the coordinates make a right diagonal line
    else if (start_row < end_row && start_col < end_col) {
        
        if (is_valid_coord(canvas, start_row, start_col) && is_valid_coord(canvas, end_row, end_col)) {
            //This writes the line
            for (int row = start_row, col = start_col; row <= end_row && col <= end_col; row++, col++) {
                if (canvas->data[row][col] == '\\' || canvas->data[row][col] == '|' || canvas->data[row][col] == '-' || canvas->data[row][col] == '+') {
                    canvas->data[row][col] = '+';
                    //if the do overlape, continue with the normal line
                } else {
                    canvas->data[row][col] = '/';
                }
            }
        } else {
            printf("Invalid coordinates for a right diagonal line.\n");
        }
    }
    else if (start_row > end_row && start_col > end_col) {
        if (is_valid_coord(canvas, start_row, start_col) && is_valid_coord(canvas, end_row, end_col)) {
            //This writes the line
            for (int row = end_row, col = end_col; row <= start_row && col <= start_col; row++, col++) {
                if (canvas->data[row][col] == '\\' || canvas->data[row][col] == '|' || canvas->data[row][col] == '-' || canvas->data[row][col] == '+') {
                    canvas->data[row][col] = '+';
                    //if the do overlape, continue with the normal line
                } else {
                    canvas->data[row][col] = '/';
                }
            }
        } else {
            printf("Invalid coordinates for a right diagonal line.\n");
        }
    }
    else {
        printf("Improper draw command.");
    }
    //This shows the new canvas with the edit
    printCanvas(canvas);
}

//This function erases a character a row and col then replaces it with a blank character
void erase_comm(Canvas *canvas, int row, int col) {
    //This checks if the coordinate is in the canvas
    if (!is_valid_coord(canvas, row, col)) {
        printf("Coordinates are outside the canvas boundaries. Cannot erase.\n");
        return;
    }
    //This replaces the character at row and col to the black space character
    canvas->data[row][col] = '*';
    //This shows the new canvas with the edit
    printCanvas(canvas);
}

//THis function resizes the canvas by making more spaces
void resize_comm(Canvas *canvas, int num_rows, int num_cols) {
    //This checks if the row and col is greater than zero
    if (num_rows <= 0 || num_cols <= 0) {
        printf("Invalid number of rows or columns. Cannot resize canvas.\n");
        return;
    }
    //This makes more space for the new size of the canvas
    char **new_data = (char **)malloc(num_rows * sizeof(char *));
    //This makes space in the canvas and put in blank space characters
    for (int i = 0; i < num_rows; i++) {
        new_data[i] = (char *)malloc(num_cols * sizeof(char));
        if (new_data[i] == NULL) {
            printf("Memory allocation error. Cannot resize canvas.\n");
            //This frees up the memory before the new canvas
            for (int j = 0; j < i; j++) {
                free(new_data[j]);
            }
            free(new_data);
            return;
        }
        for (int j = 0; j < num_cols; j++) {
            new_data[i][j] = '*';
        }
    }
    //This puts the old canvas content to the new canvas
    for (int i = 0; i < num_rows && i < canvas->num_rows; i++) {
        for (int j = 0; j < num_cols && j < canvas->num_cols; j++) {
            new_data[i][j] = canvas->data[i][j];
        }
    }
    //This frees the old canvas
    for (int i = 0; i < canvas->num_rows; i++) {
        free(canvas->data[i]);
    }
    free(canvas->data);
    //This saves the new data from resizeing
    canvas->data = new_data;
    canvas->num_rows = num_rows;
    canvas->num_cols = num_cols;
    //This shows the new canvas with the edit
    printCanvas(canvas);
}

//This function adds a row or column to the canvas
void add_comm(Canvas *canvas, char type, int position) {
    //This checks if the user wants to add a row
    if (type == 'r') {
        if (position >= 0 && position <= canvas->num_rows) {
            //This adds the number of rows by one
            canvas->num_rows++;

            //This makes space in the canvas for the addition
            canvas->data = (char **)realloc(canvas->data, canvas->num_rows * sizeof(char *));

            //This moves the content in the canvas up by one
            for (int row = canvas->num_rows - 1; row > position; row--) {
                canvas->data[row] = canvas->data[row - 1];
            }

            //This fills the new row with a blank space character
            canvas->data[position] = (char *)malloc(canvas->num_cols * sizeof(char));
            for (int col = 0; col < canvas->num_cols; col++) {
                canvas->data[position][col] = '*';
            }
        } else {
            printf("Invalid position for adding a row.\n");
        }
    } 
    //This checks if the user wants to add a row
    else if (type == 'c') {
        if (position >= 0 && position <= canvas->num_cols) {
            //This adds the number of rows by one
            canvas->num_cols++;
            for (int row = 0; row < canvas->num_rows; row++) {
                //This makes space in the canvas for the addition
                canvas->data[row] = (char *)realloc(canvas->data[row], canvas->num_cols * sizeof(char));

                //This moves the content in the canvas up by one
                for (int col = canvas->num_cols - 1; col > position; col--) {
                    canvas->data[row][col] = canvas->data[row][col - 1];
                }

                //This fills the new row with a blank space character
                canvas->data[row][position] = '*';
            }
        } 
        else {
            printf("Invalid position for adding a column.\n");
        }
    }

    //This shows the new canvas with the edit
    printCanvas(canvas);
}

//This function deletes a row or column from the canvas
void delete_comm(Canvas *canvas, char type, int position) {
    //This checks if the given row and col is in the canvas
    if ((type == 'r' && (position < 0 || position >= canvas->num_rows)) ||
        (type == 'c' && (position < 0 || position >= canvas->num_cols))) {
        printf("Invalid position for deleting %s. Cannot delete.\n", (type == 'r' ? "row" : "column"));
        return;
    }

    //This checks if the user wants to delete a row
    if (type == 'r') {
        //This frees up the row that is being removed
        free(canvas->data[position]);

        //This moves the content in the canvas down by one
        for (int i = position; i < canvas->num_rows - 1; i++) {
            canvas->data[i] = canvas->data[i + 1];
        }

        //This updates the size and num of rows
        canvas->num_rows--;
        canvas->data = (char **)realloc(canvas->data, canvas->num_rows * sizeof(char *));
    } 
    //This checks if the user wants to delete a row
    else if (type == 'c') {
        //This moves the content in the canvas to the left by one
        for (int i = 0; i < canvas->num_rows; i++) {
            for (int j = position; j < canvas->num_cols - 1; j++) {
                canvas->data[i][j] = canvas->data[i][j + 1];
            }
            //This updates the space size of the canvas
            canvas->data[i] = (char *)realloc(canvas->data[i], (canvas->num_cols - 1) * sizeof(char));
        }

        //This updates the number of columns
        canvas->num_cols--;
    }

    //This shows the new canvas with the edit
    printCanvas(canvas);
}

//This function saves the exact canvas to a file
void save_comm(Canvas *canvas, const char *file_name) {
    //This opens the file
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file for saving: %s\n", file_name);
        return;
    }

    //This writes the current canvas into a file
    for (int i = canvas->num_rows - 1; i >= 0; i--) {
        //This puts the number of rows
        fprintf(file, "%d ", i);
        //This puts the content of the canvas in the file
        for (int j = 0; j < canvas->num_cols; j++) {
            fprintf(file, "%c ", canvas->data[i][j]);
        }
        //This starts a new row after the end of every row
        fputc('\n', file); 
    }
    //This puts the number of columns
    fprintf(file, " ");
    for (int j = 0; j < canvas->num_cols; j++) {
        fprintf(file, " %d", j);
    } 

    fprintf(file, "\n");

    //This closes the file
    fclose(file);
    //This shows the new canvas with the edit
    printCanvas(canvas);
}

