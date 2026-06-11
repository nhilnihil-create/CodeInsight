#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n,m;
    cin>>n>>m;
    if(n>=m){
        cout<<min(n,m/2);
    }else {
        ll com=m/2;
        ll ans=0;
        if(com>=n){
            ans+=n;
            com-=n;
            cout<<ans+(com)/2;
        }else{
            cout<<com;
        }
    }
}