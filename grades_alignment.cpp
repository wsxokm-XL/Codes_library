//graces_alignment.cpp
/*
将输入的学生成绩（学生个数<=1500,分数为整数且>=0 && <=150）进行排序，O(n)算法
ps：若分数不为整数或者为负数，*10 或者 +固定值 使之为正整数
*/

#include<iostream>
using namespace std;

int main()
{
    struct node {
        char *name;
    };

    struct stu {
        struct node s[1500];
        int size=0;
    } num[151];

    int n,score,m;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>score;
        num[score].s[num[score].size].name=new char[10];
        cin>>num[score].s[num[score].size].name;
        num[score].size++;
    }

    for(int i=150;i>=0;i--)
    {
        m=num[i].size;
        while(m>0)
        {
            m--;
            cout<<i<<" "<<num[i].s[m].name<<endl;
            //delete num[i].s[m].name; //释放内存空间
        }
    }

    return 0;
}