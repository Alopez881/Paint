#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canvas.h" 
#include "commands.h" 
//This file gets the user input and calls the commands

//This function asks the user for commands and carries out the command
int main(int argc, char *argv[]) {
    //THis is the default sizes for the dimensions
    int num_rows = 10;  
    int num_cols = 10; 
    Canvas canvas;

    //THis checks if there are dimension numbers in the command line
    if (argc == 3) {
        num_rows = atoi(argv[1]);
        num_cols = atoi(argv[2]);

        //THis checks if the numbers in the command line are greater than 0 or else make the canvas a default size
        if (num_rows < 1 || num_cols < 1) {
            printf("The number of rows is less than 1. Making default board of 10 X 10.");
            num_rows = 10;
            num_cols = 10;
        }
    }

    //THis calls for the making of the canvas
    empty_canvas(&canvas, num_rows, num_cols);
    //This shows the user the canvas
    printCanvas(&canvas);

    int i = 1;
    //This asks the user for commands that should not surpass 21 commands
    while (i <= 21) {
        char command[100];
        printf("Enter your command: ");
        fgets(command, sizeof(command), stdin);
        char comm;  
        //This saves the first character in the command into a variable 
        if (sscanf(command, " %c", &comm) == 1) {
            
            //This checks if the user wants help
            if (comm == 'h') {
                print_help(&canvas);
            } 
            //This checks if the user wants to do something to the canvas
            else if (comm == 'w' || comm == 'e' || comm == 'r' || comm == 'a' || comm == 'd' || comm == 's' || comm == 'l' || comm == 'q') {
                int arg1 = 0;
                int arg2 = 0;
                int arg3 = 0;
                int arg4 = 0;
                char type;
                char file_name[100];
                //THis checks if the user wants to paint on the canvas
                if (comm == 'w') {
                    sscanf(command + 2, " %d  %d  %d  %d ", &arg1, &arg2, &arg3, &arg4);
                        if ((arg1 == 0 && arg2==0) && (arg3 == 0 && arg4 ==0)) {
                            sscanf(command + 2, " w  %d  %d  %d  %d ", &arg1, &arg2, &arg3, &arg4);
                        }
                    write_comm(&canvas, arg1, arg2, arg3, arg4);   
                } 
                //This checks if the user wants to erase a point on the canvas
                else if (comm == 'e' && sscanf(command + 2, " e  %d  %d", &arg1, &arg2) == 2) {
                    erase_comm(&canvas, arg1, arg2);
                }
                //This checks if the user wants to resize the canvas
                else if (comm == 'r' && sscanf(command + 2, " r  %d  %d", &arg1, &arg2) == 2) {
                    resize_comm(&canvas, arg1, arg2);
                }
                //This checks if the user wants to add a row or column
                else if (comm == 'a') {
                    
                    sscanf(command + 2, " %c %d ", &type, &arg1);
                    if (type == 'a') {
                       sscanf(command + 2, " a %c %d ", &type, &arg1); 
                    }

                    add_comm(&canvas, type, arg1);
                } 
                //This checks if the user wants to delete a row or columns
                else if (comm == 'd' ) {
                    char type1;
                    sscanf(command + 2, " %c %c %d ", &type1, &type, &arg1);
                    delete_comm(&canvas, type, arg1);
                } 
                //This checks if the user wants to save the canvas onto a file
                else if (comm == 's' && sscanf(command + 2, " s  %s", file_name) == 1) {
                    save_comm(&canvas, file_name);
                } 
                //This checks if the user wants to load cavas content from a file onto the canvas
                else if (comm == 'l' && sscanf(command + 2, " l  %s", file_name) == 1) {
                    //load_comm(&canvas, file_name);
                } 
                //THis checks if the user wants to quit the program
                else if (comm == 'q') {
                    freeCanvas(&canvas);
                    return 0;
                }

                i++;
            }
            else{
                printf("Unrecognized command. Type h for help.");
                printCanvas(&canvas);
            }
        }
    }
    //This calls to frees up the memory of the canvas
    freeCanvas(&canvas);
    return 0;
}
