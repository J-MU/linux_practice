#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char *argv){
	int pid;
    
    pid=fork();
    
    if(pid<0){ // 오류가 발생했음.
	fprintf(stderr,"Fork Failed");
	return 1;    
    }else if(pid==0){ // 자식 프로세스
    	execlp("/bin/ls","ls",NULL);
    }else{
	wait(NULL);
	printf("Child complete\n");	
    }
}
