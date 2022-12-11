#include <unistd.h>
#include <curses.h>

int main(){
	initscr();

	clear();
	
	for( int i=0; i<LINES; i++){
		move(i,i+i);
		if(i%2==1)
			standout(); //글자를 집중 모드로 나타냄.
		addstr("Hello, world");
		if(i%2==1)
			standend(); // 글자 집중모드 종료
	}

	refresh();
	sleep(3);
	endwin();

	return 0;
}
