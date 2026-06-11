#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(3*n);
    rep(i,3*n) cin>>a[i];
    sort(a.begin(),a.end());
    ll sum=0;
    rep(i,n) sum+=a[n+2*i];
    cout<<sum<<"\n";
    return 0;
}