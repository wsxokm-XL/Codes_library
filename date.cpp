//date.cpp
/*
输入三个正整数month、day、year分别表示月、日、年。
首先检验输入是否表示一个合法的日期，
如果是合法日期则计算dayNum表示此日期为该年的第几天
否则输出"Illegal" 
*/

#include<iostream>
using namespace std;

int main() 
{ int y,m,d,a,b,c,dn,j;
    cin>>y>>m>>d;

    a=y%4;
    b=y%100;
    c=y%400;
    dn=31*(m-1)+d;

    if ((a==0&&b!=0)||c==0)
        switch (m){
        case 1: j=31-d;break;

        case 2: j=29-d;break;

        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:{j=31-d;
                dn=dn-(4*m+23)/10+1;} break;

        case 4:
        case 6:
        case 9:
        case 11:
        {j=30-d;
        dn=dn-(4*m+23)/10+1;} break;

        default: j=-1;break;}

    else
        switch (m){
        case 1: j=31-d;break;

        case 2: j=28-d;break;

        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:{j=31-d;
                dn=dn-(4*m+23)/10;} break;

        case 4:
        case 6:
        case 9:
        case 11:
        {j=30-d;
        dn=dn-(4*m+23)/10;} break;

        default: j=-1;break;}

    if(j>=0)
    cout<<dn<<endl;

    else
    cout<<"Illegal"<<endl;

  return 0;
}


