#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[3];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int lohan = 100;
int kepiting = 100;
int x;
int length=10;//inisialisasi jumlah looping

void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {
        system("clear");
//        for(iter=length;iter>0;iter--)
	while(1)  
      {

        system("clear");

	printf("LOHAN 1 : %i kepiting 2: %i \n1 BERI MAKAN LOHAN \n2 BERI MAKAN KEPITING\n",lohan,kepiting);
            fflush(stdout);
            sleep(10);

	lohan=lohan-15;
            
	if(lohan<=0 || lohan>100)
        {
//		system("clear");
                printf("PERMAINAN BERAKHIR\n");
                exit(0);
        }
	    

//            system("clear");
//	    lohan=lohan-15;
	
        }        
    }
    else if(pthread_equal(id,tid[1]))
    {

	 system("clear");
//        for(iter=0;iter<length;iter++)
	while(1)
        {
		system("clear");

		printf("LOHAN 1 : % i KEPITING 2 : %i \n1 BERI MAKAN LOHAN \n2 BERI MAKAN KEPITING\n",lohan,kepiting);
            fflush(stdout);
            sleep(20);

		kepiting=kepiting-10;
            
	if(kepiting<=0 || kepiting>100)
        {
//		system("clear");
                printf("PERMAINAN BERAKHIR\n");
                exit(0);
        }
	 
//            system("clear");
//	    kepiting=kepiting-10;
        }

    }   
	else if(pthread_equal(id,tid[2]))
	{	
//		system("clear");
		while(1)
		{	
//			system("clear");
//			printf("lul :");
			scanf("%d",&x);
			if(x==1)
			{	
				printf("LOHAN MAKAN +10\n");
				lohan=lohan+10;
				if(lohan>100)
				{
					printf("LOHAN MATI KEKENYANGAN PERMAINAN BERAKHIR");
                			exit(0);
				}
			}
			else if(x==2)
			{
				printf("KEPITING MAKAN + 10\n");
				kepiting=kepiting+10;
				if(kepiting>100)
                                {
                                        printf("KEPITING MATI KEKENYANGANPERMAINAN BERAKHIR");
                                        exit(0);
                                }
			}
		}
	}
	
    return NULL;
}
int main(void)
{
    int i=0;
    int err;
    while(i<3)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);

//	printf("lohan : %d kepiting : %d\n",lohan,kepiting);
    return 0;
}

