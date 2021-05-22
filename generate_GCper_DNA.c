//generate_GCper_DNA.c
/*
生成指定GC含量的长度为n的随机DNA序列
*/

srand(time(NULL));

#include<stdlib.h>
#include<time.h>

char random_AT()
{
	int random=rand()%2;
	return "AT"[random];
}

char random_CG()
{
	int random=rand()%2;
	return "CG"[random];
}

void random_seq(int length,int GCp,char *seq)
{
	int i;
	int GCn=GCp*(length)/100;

	int *arr;int rand_tmp;
	arr=(int*)malloc(sizeof(int)*(length)); 
	for(i=0;i<length;i++)
		arr[i]=i;
	for(i=0;i<length;i++)
	{
		rand_tmp=rand()%(length);
		if(rand_tmp!=i)
		{
			arr[i] ^=arr[rand_tmp];
			arr[rand_tmp] ^=arr[i];
			arr[i] ^=arr[rand_tmp];
		}
	}

	char tmp;
	for(i=0;i<length;i++)
	{
		if(arr[i]<GCn)
			tmp=random_CG();
		else
			tmp=random_AT();

		seq[i]=tmp;
	}
	seq[length]='\0';
	free(arr);
}//若GC含量为41%，则GCp=41；