#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>

int x=10;

void *runner(void *param){
	x+=10;
	pthread_exit(0);
}

int main(){
	int i;
	pid_t pid1,pid2;

	pthread_t tid;
	pid1=fork();

	if(pid1==0){
		pthread_create(&tid,NULL,runner,NULL);
		pthread_join(tid,NULL);
		pid2=fork();
		if(pid2>0){
			wait(NULL);
			x+=10;
		}
		printf("%d ",x);
	}else{
		wait(NULL);
		printf("%d ",x);
	}
}
