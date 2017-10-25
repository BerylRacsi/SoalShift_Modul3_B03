#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>


pthread_t tid[2];

int length=157;
void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    if(pthread_equal(id,tid[0]))
    {
        system("clear");
        for(iter=length;iter>0;iter--)
        {
            printf("%i",iter);
            fflush(stdout);
            sleep(1);
            system("clear");
        }
    }
    else if(pthread_equal(id,tid[1]))
    {
        system("xlogo");
    }
    return NULL;
}
int main(void)
{
    key_t key = 1234;
    int *senjata1, *senjata2, *senjata3, *senjata4, *senjata5;	
    int i=0;
    int err;
    while(i<2)
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);
        if(err!=0)
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
    return 0;
}
