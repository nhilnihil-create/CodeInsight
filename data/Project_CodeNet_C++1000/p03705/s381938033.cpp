#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,a,b,i;
    cin>>n>>a>>b;
    if(a>b)
    {
        cout<<0;
    }
    else if(n==1 && a!=b)
    {
        cout<<0;
    }
    else
    {
        n--;
        cout<<(a+(n*b))-(b+(n*a))+1;
    }
    return 0;
}