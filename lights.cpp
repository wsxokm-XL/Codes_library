//lights.cpp
/*
有 1000盏灯，编号为 1~ n ~ 1000。
一共有k个人，第n个人按下编号为n的倍数的灯的开关。
输出开着的灯的编号。
*/
#include<iostream>

using namespace std;
int main() 
{
    int n,k,x;

    cin>>n>>k;

    for(int i=1;i<=n;i++){
        x=0;
        for(int j=1;j<=k;j++){
            if(i%j==0) x=x+1;
        }
        if(x%2!=0) cout<<i<<" ";
    }
  return 0;
}