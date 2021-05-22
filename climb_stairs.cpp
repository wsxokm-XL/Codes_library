//climb_stairs.cpp
/*
要走上一个有n级台阶的楼梯，
你可以一次走一级，也可以一次走两级。
计算有多少种走法。
*/
#include<iostream>
using namespace std;

int main()
{
    int n,a,x,y,z,s=1;//x两级次数,y总步数,z每种情况下的走法数,s总走法（当x=0时有1种走法）

    cin>>n;

    a=n/2;

    for(int i=1;i<=a;i++){
        x=i;
        y=n-x;
        z=1;

        for(int j=1;j<=x;j++){
            z=z*y/j;
            y--;
        }

        s=s+z;
        
    }

    cout<<s<<endl;
    
	return 0;
}