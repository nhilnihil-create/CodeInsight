#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    ll n,m; cin >> n >> m;
    ll s=0,c=0;
    ll ans = min(n,m/2);
    c=m-ans*2;
    if(c>1){
        ans+=c/4;
    }
    cout << ans << endl;
}