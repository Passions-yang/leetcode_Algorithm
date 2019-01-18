#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>

#ifndef ADD_LINUX_SEPARATOR
#define ADD_LINUX_SEPARATOR(ret_buf,path,name) \
    if('/' == path[strlen(path)-1]){ \
        sprintf(ret_buf,"%s%s",path,name); \
    }else{ \
        sprintf(ret_buf,"%s/%s",path,name); \
    }
#endif /*ADD_LINUX_SEPARATOR*/



int check_dir(const char *path)
{     
	DIR *pDir = NULL;     
	struct dirent *p_dirent;
    assert(NULL != dir_path);
	pDir = opendir(path);
    if(pDir==NULL)
	{         
		return -1;
    }
    while(p_dirent=readdir(pDir))
	{
         if(strcmp(p_dirent->d_name,".")!=0&&strcmp(p_dirent->d_name,"..")!=0)
		 return -1;
	}
	return 0;
}

int rm_empty_dir(const char *dir_path)	
{		
	DIR *pDir;  
	struct stat st;
	struct dirent *ptr;
    assert(NULL != dir_path);
	pDir=opendir(dir_path);		
	if(pDir==NULL)		
	{         
		return -1;		
	}		
	char buf[64] = {0};
	if(check_dir(dir_path)){	
	    while((ptr=readdir(pDir))!=NULL){			
		    memset(&st,0x00,sizeof(struct stat));
		    memset(buf,0x00,sizeof(buf));
            ADD_LINUX_SEPARATOR(buf,dir_path,ptr->d_name)
		    if(-1 == (lstat(buf, &st)))			
			    return -1;			
		    if(S_ISDIR(st.st_mode)){		
			    if(strcmp(ptr->d_name,".")!=0 && strcmp(ptr->d_name,"..")!=0){		
				    rm_empty_dir(buf);
			    }					
		    }else{
                printf("***************path : %s\n",buf);
            }
	   }	
    }
    return 0;
}
int main(int argc,char * argv[])
{
    rm_empty_dir(argv[1]);
    return 0;
}
