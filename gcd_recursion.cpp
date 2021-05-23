//gcd_recursion.cpp
/*
输入两个整数m，n，输出它们的最大公约数（gcd）
递归
*/
#include <iostream>
using namespace std;

int Gcd(int a,int b)
{
    if(a>b) return Gcd(a-b,b);
    else if(a<b) return Gcd(a,b-a);
    else if(a==b) return a;
}

int main()
{
    int a,b;
    cin>>a>>b;
	cout<<Gcd(a,b);
    return 0;
}