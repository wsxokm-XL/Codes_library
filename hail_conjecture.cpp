//hail_conjecture.cpp
/*
给出一个正整数 n(*n*≤100)，然后对这个数字一直进行下面的操作：
如果这个数字是奇数，那么将其乘 3 再加 1，否则除以 2。
经过若干次循环后，最终都会回到 1。
根据给定的数字 n，验证这个猜想，即输出整个变化序列。
*/
#include<iostream>
using namespace std;

void hail(int n){
    do{
    cout<<n<<" ";

    switch(n%2){
        case 0:n=n/2;break;
        case 1:n=3*n+1;break;
    }

    } while (n!=1);

    cout<<n;
    
}

int main()
{
    int n;
    cin>>n;
    hail(n);
    return 0;
}