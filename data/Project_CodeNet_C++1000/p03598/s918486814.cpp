#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,k;
    cin>>n>>k;ll l1[n+1],x,s=0,a,b;
    for(int i=1;i<=n;i++){
        cin>>x;
        a=x*2;
        b=abs(k-x)*2;
        s+=min(a,b);
    }
    cout<<s;
}
