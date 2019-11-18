#include "my.h"

int main()
{
	int var;
  	pid_t pid;
	FILE *fp;
	char p[] = {"It's Father\n"};
	char s[] = {"It's Son\n"};
 	var=88;
  	printf("before fork\n");
  	if((pid=vfork())<0)
	{
    	perror("create failure");
  	}
	else if(pid==0)
	{
    	var++;
		printf("pid=%d,var=%d\n",getpid(),var); 
		if((fp=fopen("test.dat","a"))==NULL)
		{
			perror("Failed to fopen\n");
			return -1;
		}
		if(fputs(s,fp)==EOF)
		{
			perror("Failed to fput\n");
			return -1;
		}

    }
	
	else
	{
    	if((fp=fopen("test.dat","a"))==NULL)
		{
			perror("Failed to fopen\n");
			return -1;
		}
		if(fputs(p,fp)==EOF)
		{
			perror("Failed to fput\n");
			return -1;
		}
		
	}

	printf("pid=%d,var=%d\n",getpid(),var); 

	fclose(fp);

    return 0;  
}
