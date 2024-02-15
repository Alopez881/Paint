void print_help(){

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
}

printf("Wrong number of command line arguments entered.\n");
printf("Usage: ./paint.out [num_rows num_cols]\n");

printf("Unrecognized command. Type h for help.\n");
printf("Enter your command: ");

printf("The number of rows is not an integer.\n");
printf("The number of rows is less than 1.\n");

printf("The number of columns is not an integer.\n");
printf("The number of columns is less than 1.\n");

"Improper draw command.\n"
"Improper resize command.\n"
"Improper erase command.\n"
"Improper add command.\n"
"Improper delete command.\n"
"Improper save command or file could not be created.\n"
"Improper load command or file could not be opened.\n"