#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smsh.h"

char * next_cmd(char *prompt,FILE *fp){
	char *buf;
	int bufspace=0;
	int pos=0;
	int c;

	printf("%s",prompt);
	while((c=getc(fp))!=EOF){
		if(pos+1>=bufspace){
			if(bufspace==0)
				buf=emalloc(BUFSIZ);
			else
				buf=erealloc(buf,bufspace+BUFSIZ);
			bufspace+=BUFSIZ;
		}
		
		// end of command?
		if(c=='\n')
			break;

		// no add to buffer
		buf[pos++]=c;
	}
	
	if(c==EOF && pos==0) // EOF and no input
	buf[pos]='\0';
	return buf;
}
