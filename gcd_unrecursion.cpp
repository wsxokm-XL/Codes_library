//gcd_unrecursion.cpp
/*
输入两个整数m，n，输出它们的最大公约数（gcd）
非递归实现
*/
#include<iostream>
using namespace std;

int main() 
{ 
    int n, m ,x, gcd;
    cin>>n>>m;
        x=max(n,m);
        m=min(n,m);
        n=x;
    for(int i=1; ;i++){
        x=m;
        m=n%m;
        n=x;
        if(m==0) break;
    }
    cout<<n<<endl;

  return 0;
}
