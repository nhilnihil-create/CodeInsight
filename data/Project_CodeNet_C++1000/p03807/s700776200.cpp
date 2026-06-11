#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b,c,d,i,t,e=0,o=0;
    cin>>a;
    int s[a];
    for(i=0;i<a;i++)
    {
        cin>>s[i];
        if(s[i]%2==0)e++;
        else if(s[i]%2==1)o++;

    }if(o==0)cout<<"YES";
    else if(o%2==0)cout<<"YES";
    else cout<<"NO";
}
