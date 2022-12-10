#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

int total_words;

void* count_words(void* file_name){
	char *fileName=(char*)file_name;
	FILE *fp;
	int c,prevc='\0';

	if((fp=fopen(fileName,"r"))!=NULL){ // file open이 성공한다면
		while((c=getc(fp))!=EOF){   //file이 끝났는지 확인해보기.

			if(!isalnum(c) && isalnum(prevc)){
				total_words++;
			}
			prevc=c;
		}
		fclose(fp);
	}else{
		perror(fileName);
	}

	return NULL;
}


int main(int ac,char *av[]){
	pthread_t t1,t2;
	void * count_words(void*);


	if(ac!=3){
		printf("usage: %s file1 file2\n",av[0]);
		exit(1);
	}

	total_words=0;

	pthread_create(&t1,NULL,count_words,(void*) av[1]);
	pthread_create(&t2,NULL,count_words,(void*) av[2]);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("%5d: total words\n",total_words);

	return 0;
}

