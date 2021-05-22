//KMP.c
/*
字符串匹配
有一个字符串S和一个模式字符串P，如何查找P在S中的位置？
KMP算法
*/
#include<string.h>
void get_next(const char*tmp,int *next)
{
	next[0]=-1;
	int i=0,j=-1;
	int l=strlen(tmp);

	while(i<l)
	{
		if(j==-1||tmp[i]==tmp[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}//求得next数组

int KMP(const char*tmp,const char*src)
{
	int next[strlen(src)];
	get_next(src,next);

	int a=0,b=0;
	int l1=strlen(tmp),l2=strlen(src);
	while(a<l1&&b<l2)
	{
		if(b==-1||tmp[a]==src[b])
		{
			a++;
			b++;
		}
		else b=next[b];
	}
	if(b==l2)
		return a-b;
	else
		return -1;
}//KMP算法