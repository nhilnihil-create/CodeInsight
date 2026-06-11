#include<bits/stdc++.h>
#define ll long long int
using namespace std;

map<ll,ll>l2;

int main()
{
    ll n;
    cin>>n;
    ll s=0;
    for(int i = 1; i<=n;i++){
        ll a,b;
        cin>>a>>b;
        s+=b-a+1;
    }
    cout<<s;

    return 0;
}
