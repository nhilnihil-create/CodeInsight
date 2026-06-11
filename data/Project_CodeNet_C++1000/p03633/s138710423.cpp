#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll n;
    cin>>n;ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }
    if(n==1){cout<<l1[1];return 0;}
    ll x=(ll)((ll)(l1[2]/__gcd(l1[1],l1[2]))*l1[1]);
    //cout<<x<<endl;
    for(int i=3;i<=n;i++){
        x=(ll)((ll)(l1[i]/__gcd(x,l1[i]))*x);
    }
    cout<<x;

    return 0;
}
