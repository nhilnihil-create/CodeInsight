#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
int main()
{
    ///"In the name of Allah,most gracious and most merciful"///

    ll i,j,x,y,z,count=100000000000,sum=0,n,ans=0;
    cin>>x>>y>>z;
    j=y/z;
    i=x/z;
    if(x%z==0)
        cout<<(j-i+1)<<endl;
    else
        cout<<(j-i)<<endl;

    return 0;
}





