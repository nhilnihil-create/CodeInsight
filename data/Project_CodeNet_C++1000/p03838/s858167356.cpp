#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll x,y;
    cin >> x >> y;
    ll ans=MOD;
    ll cx=x*(-1);
    ll cy=y*(-1);
    if(x<=y){
        ans=min(ans,y-x);
    }
    if(cx<=y){
        ans=min(ans,y-cx+1);
    }
    if(x<=cy){
        ans=min(ans,cy-x+1);
    }
    if(cx<=cy){
        ans=min(cy-cx+2,ans);
    }
    cout << ans << endl;
}