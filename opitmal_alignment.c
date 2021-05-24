//opitmal_alignment.c
/*
随机生成2个长度为100，GC含量为41%的随机DNA序列。
根据打分规则（match=3,mismatch=-3,gap=-2）
输出最优的成对全局比对。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define LEN 100
#define GC 41

int match=3,mismatch=-3,gap=-2;

struct dna
	{
		char sequence[LEN+1];
	};
typedef struct dna Dna;

Dna dna1,dna2;

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
} 

int score(char *seq1,char *seq2, int back[LEN+1][LEN+1])
{
	int matrix[LEN+1][LEN+1];
	int m,n;
	int left,up,leftup;
	matrix[0][0]=0;
	for(m=1;m<LEN+1;m++)
	{
		matrix[m][0]=matrix[m-1][0]+gap;back[m][0]=-2;//回溯到左上单元格+3，回溯到上单元格-2，回溯到左单元格-4
		matrix[0][m]=matrix[0][m-1]+gap;back[0][m]=-4;//back=3,1,-1,-3;-2,-6;-4 分别对应7种情况。
	}
	for(m=1;m<LEN+1;m++)
		for(n=1;n<LEN+1;n++)
			{
				left=matrix[m][n-1]+gap;up=matrix[m-1][n]+gap;
				if (seq1[n-1]==seq2[m-1])
					leftup=matrix[m-1][n-1]+match;
				else
					leftup=matrix[m-1][n-1]+mismatch;

				if(leftup>left)
					{
						if(leftup>up)
						{
							matrix[m][n]=leftup;
							back[m][n]=3;
						}//左上
						else if (leftup<up)
						{
							matrix[m][n]=up;
							back[m][n]=-2;
						}//上	
						else
						{
							matrix[m][n]=up;
							back[m][n]=-2+3;
						}//左上和上
					}
				else if (leftup<left)
					{
						if(left>up)
						{
							matrix[m][n]=left;
							back[m][n]=-4;
						}//左
						else if (left<up)
						{
							matrix[m][n]=up;
							back[m][n]=-2;
						}//上	
						else
						{
							matrix[m][n]=up;
							back[m][n]=-2-4;
						}//左和上
					}
				else
					{
						if(left>up)
						{
							matrix[m][n]=left;
							back[m][n]=-4+3;
						}//左上和左
						else if (left<up)
						{
							matrix[m][n]=up;
							back[m][n]=-2;
						}//上	
						else
						{
							matrix[m][n]=up;
							back[m][n]=-2-4+3;
						}//左上和左和上
					}
			}//matrix[m][n]=max{matrix[m-1][n]+gap,matrix[m][n-1]+gap,matrix[m-1][n-1]+(mis)match}

	return matrix[LEN][LEN];
}//打分函数

int main()
{
	srand(time(NULL));
	random_seq(LEN,GC,dna1.sequence);
	random_seq(LEN,GC,dna2.sequence);
	int back[LEN+1][LEN+1];

	printf("seq1:%s",dna1.sequence);
	printf("\n");
	printf("seq2:%s",dna2.sequence);
	printf("\n");

	int s=score(dna1.sequence,dna2.sequence,back);
	printf("score:%d\n",s);

	char S[2*LEN],T[2*LEN];int m=LEN,mm=LEN,n=LEN,nn=LEN,i=0,j=0;

	while(1)
	{
		switch (back[mm][nn]){
		case 3:
		case 1:
		case -1:
		case -3: {mm--;nn--;m--;n--;S[i]=dna1.sequence[m];T[j]=dna2.sequence[n];i++;j++;break;}
		case -2:
		case -6: {mm--;n--;S[i]='-';T[j]=dna2.sequence[n];i++;j++;break;}
		case -4: {nn--;m--;S[i]=dna1.sequence[m];T[j]='-';i++;j++;break;}
		}

		if(mm==0&&nn==0)
			break;
	}

	for(;i>=0;i--)
	printf("%c",S[i]);

	printf("\n");

	for(;j>=0;j--)
	printf("%c",T[j]);

	printf("\n");

	return 0;
}