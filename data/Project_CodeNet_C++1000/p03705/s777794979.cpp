
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,n;
signed main()
{
    cin>>n>>a>>b;
    if(a>b)cout<<0,exit(0);
    if(n==1&&a!=b)cout<<0,exit(0);
    cout<<b*(n-1)+a-(a*(n-1)+b)+1;

}
/*
先考虑加一个点。这个点先排在根的位置，然后两个儿子可以枚举一波。
3422702
*/


