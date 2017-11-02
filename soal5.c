#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char ch;
	char temp[10],tofind[10];
	int wordcount, count;

	wordcount = 0;
	count = 0;

  

  	fp = fopen("Novel.txt","r");
	scanf("%s",tofind);
   
	if ( fp )
	{
		

//		while ((ch=getc(fp)) != EOF) {
//
//			if(ch==' ')
//			{
//				temp[count]='\0';
//				if(strcmp(temp,tofind)==0)
//				{
//					++wordcount;
//				}
//			}
//		   }
//		if (charcount > 0) {
//		++wordcount;
//		}
	}
	else
	{
		printf("Failed to open the file\n");
        }


	printf("Words : %d \n", wordcount);


	getchar();
	return(0);
}
