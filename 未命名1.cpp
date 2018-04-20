#include "stdio.h"
#include "string.h"
#include "stdlib.h"
 
int charcalculate=0;
 
int wordcalculate=0;
 
int centancecalculate=0;
 
void calculate(char * file)
{
    FILE * fp;
    int b=0;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("read file failed£¡\n");
        exit(-1);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);
		if((a==' '||a=='\n'||a=='\t'||a==','||a=='.'||a=='!'||a=='='||a==';')&&b==1)
        {
			wordcalculate++;
			}
		
           if((a=='.'||a=='!'||a=='?')&&b==1)
        {
			centancecalculate++;
			}
		b=0;
        if(a!=' '&&a!='\n'&&a!='\t'&&a!=','&&a!='.'&&a!='!'&&a!=';'&&a!='=')
        {
			charcalculate++;
            b=1;
			}
        
     
    }
  
    charcalculate--;         
    fclose(fp);
}
 
int main(int argc, char* argv[])             
{
    FILE *fp;
 
	calculate(argv[2]);
    if((fp=fopen(argv[2],"r"))==NULL)
    {  
    printf("FileNull\n\n\n");
    scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    else if(!strcmp(argv[1],"-c"))                 
        printf("File:%s CharNum:%d\n",argv[2],charcalculate);
    else if(!strcmp(argv[1],"-w"))                  
        printf("File:%s WordNum:%d\n",argv[2],wordcalculate);
    else if(!strcmp(argv[1],"-l"))                
        printf("File:%s centanceNum:%d\n",argv[2],centancecalculate);
    else if(!strcmp(argv[1],"exit"))
    {
        printf("Exit!\n");
    }
    else
        printf("NullPoint\n");
    printf("\n\n");
    
    return 0;
     
}
