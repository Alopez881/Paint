paint.out: main.c commands.c canvas.c
	gcc -g -Wall -Werror -Wextra -o paint.out main.c commands.c canvas.c
