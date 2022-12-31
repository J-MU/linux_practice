#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	pid_t pid=fork();
	if(pid>0){
		wait(NULL);
		printf("A");
	}else{
		pid=fork();
		if(pid==0){
			printf("B");
		}else{
			wait(NULL);
			printf("C");
		}
	}
	printf("D");
}
