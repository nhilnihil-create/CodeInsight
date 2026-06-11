#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,h;
int main()
{
    cin>>n>>m;
    h=min(n,m/2);
    m=m-n*2;n=0;
    m=max(m,n);
    cout<<h+m/4;
    return 0;
} 