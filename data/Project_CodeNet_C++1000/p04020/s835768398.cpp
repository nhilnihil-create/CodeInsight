#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n){
        cin>>v[i];
    }
    v.push_back(0);
    ll now = 0;
    ll ans = 0;
    rep(i, n+1){
        if(v[i] == 0) {
            ans += now/2;
            now = 0;
        }
        else now += v[i];
    }
    cout<<ans<<endl;
    return 0;
}