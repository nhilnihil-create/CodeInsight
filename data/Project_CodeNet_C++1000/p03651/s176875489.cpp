#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int mx=0,g=0;
    bool ok=false;
    rep(i,n){
        cin>>a[i];
        mx=max(mx,a[i]);
        g=__gcd(g,a[i]);
        if(a[i]==k)ok=true;
    }
    if((k%g==0&&k<=mx)||ok)cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}