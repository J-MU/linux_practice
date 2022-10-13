#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_ls(char[]);

int main(int ac,char *av[]){
	printf("ac: %d",ac);


	if(ac==1)
		do_ls(".");
	else
		while(--ac){
			printf("여기!: %s:\n", *++av);
			do_ls(*av);
		}

	return 0;
}

void do_ls(char dirname[])
{
	DIR *dir_ptr;
	struct dirent *direntp;

	if((dir_ptr=opendir(dirname))==NULL)
		fprintf(stderr,"ls1: cannot open %s\n",dirname);
	else{
		while((direntp=readdir(dir_ptr))!=NULL)
			printf("%s\n",direntp->d_name);
		closedir(dir_ptr);
	}
}
