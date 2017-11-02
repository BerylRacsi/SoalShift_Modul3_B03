#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

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
	
	char lihat[10], tambah[10], beli[10];
	int x;
	int y;
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
			if(x==1)
			{
				scanf("%s %d",lihat,&a);
			//	printf("%s %d\n",lihat,a);
			//	break;
			}
		}
		

	}
        
	shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}
