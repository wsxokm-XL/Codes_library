#include<iostream>
using namespace std;

int main()
{
    struct node {
        char name[5];
    };

    struct stu {
        struct node s[150];
        int size=0;
    } num[151];

    int n,score,m;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>score;
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
        }
    }

    return 0;
}