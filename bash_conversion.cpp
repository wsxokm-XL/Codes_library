//bash_conversion.cpp
/*
输入两个十进制正整数 n 和 base(2≤base≤16)，将 n 转换为 base 进制后输出
*/
#include<iostream>
using namespace std;

void printInt(int n,int base){
    int code[100],t=-1,z;
    for(int i=0;i<=99;i++){
        code[i]=n%base;
        t++;
        n=n/base;
        if(n==0) break;

    }
    for(int i=t;i>=0;i--){
        switch(code[i]){
        case 10: cout<<"A";break;
        case 11: cout<<"B";break;
        case 12: cout<<"C";break;
        case 13: cout<<"D";break;
        case 14: cout<<"E";break;
        case 15: cout<<"F";break;
        default: cout<<code[i];
        }
    }     
}

int main()
{
    int n, base;
    cin>>n>>base;
    printInt(n, base);
    return 0;
}

