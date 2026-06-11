#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll lcm=a[0];
    for(int i=1; i<n; ++i){
        lcm=lcm/__gcd(lcm,a[i])*a[i];
    }
    cout<<lcm<<endl;
}