#include<bits/stdc++.h>
using namespace std;

long long n,x,y,m,M, dis,flag;

void add()
{
    dis+=((long long)(M/m))*m*2;
    if(M%m==0) {dis-=m; flag=1;}
    else {long long tmp=M; M=m; m=tmp%m;}
}

int main()
{
    scanf("%lli%lli",&n,&x);
    y=n-x; m=min(x,y); M=max(x,y); dis=flag=0;
    dis+=(x+y);
    for(;flag==0;) add();
    printf("%lli\n",dis);

    return 0;
}