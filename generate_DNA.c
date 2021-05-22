//generate_DNA.c
/*
生成长度为n的随机DNA序列
*/
#include<stdlib.h>
#include<time.h>

srand(time(NULL));

char random_ATCG()
{
	int random=rand()%4;
	return "ATCG"[random];
}随机生成A、T、C、G

void random_seq(int length,char *seq)
{
	int i;
	for(i=0;i<length;i++)
	{
		seq[i]=random_ATCG();
	}
	seq[length]='\0';
} //生成随机DNA序列

