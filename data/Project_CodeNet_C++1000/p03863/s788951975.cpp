#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
char a1[2006811];
ll n,i,j,m,k,la,a[71720],b[71720],c[71720],d[71720],e[71720],f[71720],sum[71720],sumend,lsbl[71720];
int main()
{
    cin>>a1;
    la=strlen(a1);
    if(a1[0]==a1[la-1]&&!(la%2))
    {
        cout<<"First"<<endl;
        return 0;     
    }
    else if(a1[0]==a1[la-1]&&(la%2))
    {
        cout<<"Second"<<endl;
        return 0;
    }
    else if(a1[0]!=a1[la-1]&&!(la%2))
    {
        cout<<"Second"<<endl;
        return 0;
    }
    cout<<"First"<<endl;
    return 0;
}