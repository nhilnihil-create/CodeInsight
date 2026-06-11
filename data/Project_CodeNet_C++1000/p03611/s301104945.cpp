#include<bits/stdc++.h>
#define ll long long int
using namespace std;

map<ll,ll>l2;

int main()
{
    ll n,a=0,b=0,c=0,x=0,y,z;
    cin>>n;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        l2[l1[i]]++;
    }
    for(int i=0;i<100000;i++){
        if(i==0)x=max(x,l2[i]+l2[i+1]);
        else x=max(x,l2[i]+l2[i-1]+l2[i+1]);
    }
    if(x)cout<<x;
    else cout<<1;

    return 0;
}
