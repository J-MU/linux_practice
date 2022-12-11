#include <stdio.h>
#include <curses.h>

int main(){
	initscr();

	clear();
	move(10,20);
	addstr("Hello, World");
	move(LINES-1,0); //user의 input을 받기 전에 마지막줄로 커서를 이동하는듯?

	refresh();
	getch();

	endwin();

	return 0;
}
