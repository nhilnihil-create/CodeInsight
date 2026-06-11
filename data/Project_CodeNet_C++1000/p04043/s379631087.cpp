#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int a[3],i,c=0,c1=0;
    for(i=0;i<3;i++)
    {
        cin>>a[i];
        if(a[i]==5)c++;
        if(a[i]==7)c1++;
    }
    if(c==2 && c1==1)cout<<"YES\n";
    else cout<<"NO\n";
}

