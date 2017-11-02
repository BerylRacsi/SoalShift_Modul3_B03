#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main()
{
        key_t key = 1234;
	key_t key2 = 1235;
	key_t key3 = 1236;	       
	key_t key4 = 1237;
        key_t key5 = 1238;
        key_t key6 = 1239;

        int *value;
	int *value2;
	int *value3;
        int *value4;
        int *value5;
        int *value6;
	
	char s1[10] = "MP4A1";
	char s2[10] = "PM2-V1";
	char s3[10] = "SPR-3";
	char s4[10] = "SS2-V5";
	char s5[10] = "SPG1-V3";
	char s6[10] = "MINE";
	
	char tambah[10], beli[10];
	int x;
	int y;
	int z;
	int a;
	int b;
	



        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);

        int shmid2 = shmget(key2, sizeof(int), IPC_CREAT | 0666);
	value2 = shmat(shmid2, NULL, 0);

        int shmid3 = shmget(key3, sizeof(int), IPC_CREAT | 0666);
	value3 = shmat(shmid3, NULL, 0); 

	int shmid4 = shmget(key4, sizeof(int), IPC_CREAT | 0666);
        value4 = shmat(shmid4, NULL, 0); 

	int shmid5 = shmget(key5, sizeof(int), IPC_CREAT | 0666);
        value5 = shmat(shmid5, NULL, 0); 

	int shmid6 = shmget(key6, sizeof(int), IPC_CREAT | 0666);
        value6 = shmat(shmid6, NULL, 0); 

	
	while(1)
	{
		printf("----SI PENJUALAN SENJATA----\n");
		printf("1 PENJUAL\n");
		printf("2 PEMBELI\n");
		scanf("%d",&x);
		
		if(x==1)
		{
			printf("1 LIHAT STOCK\n");
			printf("2 TAMBAH STOCK\n");
			scanf("%d",&y);
			if(y==2)
			{
				scanf("%s %d",tambah,&a);
			//	printf("%s %d\n",lihat,a);
			//	break;
				if(strcmp(tambah,s1) == 0)
					*value = *value + a;
				else if(strcmp(tambah,s2) == 0)
					*value2 = *value2 +  a;
				else if(strcmp(tambah,s3) == 0)
					*value3 =*value3 + a;
                                else if(strcmp(tambah,s4) == 0)
					*value4 =*value4 + a;
                                else if(strcmp(tambah,s5) == 0)
					*value5 =*value5 + a;
                                else if(strcmp(tambah,s6) == 0)
					*value6 =*value6 + a;

			}
			else if(y==1)
			{
				printf("%s %d\n",s1,*value);
                                printf("%s %d\n",s2,*value2);
                                printf("%s %d\n",s3,*value3);
                                printf("%s %d\n",s4,*value4);
                                printf("%s %d\n",s5,*value5);
                                printf("%s %d\n",s6,*value6);

			}
		}
		
		else if(x==2)
		{
			printf("1 LIHAT STOCK\n");
                        printf("2 BELI SENJATA\n");
                        scanf("%d",&z);
			if(z==2)
			{
				scanf("%s %d",beli,&b);
                        //      printf("%s %d\n",lihat,a);
                        //      break;
                                if(strcmp(beli,s1) == 0)
                                        *value = *value - b;
                                else if(strcmp(beli,s2) == 0)
                                        *value2 = *value2 -  b;
                                else if(strcmp(beli,s3) == 0)
                                        *value3 =*value3 - b;
                                else if(strcmp(beli,s4) == 0)
                                        *value4 =*value4 - b;
                                else if(strcmp(beli,s5) == 0)
                                        *value5 =*value5 - b;
                                else if(strcmp(beli,s6) == 0)
                                        *value6 =*value6 - b;
			}
	
		}
	}
        
	shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}
