#ifndef COMMANDS_H
#define COMMANDS_H

// Include necessary headers
#include "canvas.h"

// Function prototypes for commands implemented in commands.c
void print_help(const Canvas *canvas);
void write_comm(Canvas *canvas, int start_row, int start_col, int end_row, int end_col);
void erase_comm(Canvas *canvas, int row, int col);
void resize_comm(Canvas *canvas, int num_rows, int num_cols);
void add_comm(Canvas *canvas, char type, int position);
void delete_comm(Canvas *canvas, char type, int position);
void save_comm(Canvas *canvas, const char *file_name);
//void load_comm(Canvas *canvas, const char *file_name);

#endif 
