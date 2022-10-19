#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void f(int);

clock_t start,finish;

int main(){
	void f(int);
	int i;

	signal(SIGINT, f);

	start=time(NULL);
	while(1){		
		printf("haha\n");
		sleep(1);
	}
	return 0;
}

void f(int signum)
{

	finish=time(NULL);
	int during_time=(int)(finish-start);
	printf("Currently elapsed time: %d sec(s)\n",during_time);
}
