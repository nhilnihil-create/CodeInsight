#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    vector<ll> a(3);
    rep(i,3) cin>>a[i];
    if(a[0]%2==0 ||a[1]%2==0 ||a[2]%2==0) cout<<0<<"\n";
    else{
        sort(a.begin(),a.end());
        cout<<a[0]*a[1]*(a[2]-a[2]/2)-a[0]*a[1]*(a[2]/2)<<"\n";
    }
    return 0;
}