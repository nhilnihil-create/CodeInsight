#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long



int main()
{
    ll n,t;
    cin>>n>>t;
    ll l1[n+1],x=t,s=0;
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }
    for(int i=2;i<=n;i++){
        if(l1[i]<=x)x=l1[i]+t;
        else s+=l1[i]-x,x=l1[i]+t;
    }
    cout<<x-s<<endl;
}
