//BF.c
/*
字符串匹配
有一个字符串S和一个模式字符串P，如何查找P在S中的位置？
暴力匹配算法（BF）
*/
#include<string.h>
int BF(const char*tmp,const char*src)
{
	int i,j,k,result=-1;
	int tmp_length=strlen(tmp);
	int src_length=strlen(src);
	for(i=0;i<tmp_length;i++)
	{
		if(tmp[i]==src[0])
			{
				k=1;
				for(j=1;j<src_length;j++)
				{
					if(tmp[i+j]==src[j]) k++;
					else break;
				}
				if(k==src_length) 
					{
						result=i;
						break;
					}
			}
	}
	return result;
}//tmp为字符串S，src为模式字符串P，返回S在P中首次出现的位置下标
