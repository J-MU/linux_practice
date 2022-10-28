#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_ls(char []);
void show_file_info(char *,struct stat*);

int main(int ac,char* av[]){
	if(ac==1)
		do_ls(".");
	else
		while(--ac){
			printf("%s:\n",*++av);
			do_ls(*av);
		}

	return 0;
}


void do_ls(char dirname[]){
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

void show_file_info(char *fname,struct stat *buf){
	char *uid_to_name(),*ctime,*git_to_name(),*filemode();
	void mode_to_letters();
	char modestr[11];

	mode_to_letters(info_p->st_mode,modestr);

	printf("%s",modestr);
	printf("%4d ",(int) info_p->st_nlink);
	printf("%-8s ",uid_to_name(info_p->st_uid));

}

