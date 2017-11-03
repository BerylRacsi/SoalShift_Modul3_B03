#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[2];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int lohan = 100;
int kepiting = 100;
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
	lohan=lohan-15;
            
	if(lohan<=0 || lohan>100)
        {
                printf("PERMAINAN BERAKHIR");
                exit(0);
        }
	    printf("thread 1 : %i thread 2: %i ",lohan,kepiting);
            fflush(stdout);
            sleep(10);

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

		kepiting=kepiting-10;
            
	if(kepiting<=0 || kepiting>100)
        {
                printf("PERMAINAN BERAKHIR");
                exit(0);
        }
	 printf("thread 1 : % i thread 2 : %i  ",lohan,kepiting);
            fflush(stdout);
            sleep(20);

//            system("clear");
//	    kepiting=kepiting-10;
        }

    }   
    return NULL;
}
int main(void)
{
    int i=0;
    int err;
    while(i<2)//looping membuat thread 2x
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
	printf("lohan : %d kepiting : %d\n",lohan,kepiting);
    return 0;
}

