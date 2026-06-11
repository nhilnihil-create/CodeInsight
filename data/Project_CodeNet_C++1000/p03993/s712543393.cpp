#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N+1);
    vector<vector<ll>> G(N+1);
    ll ans = 0;
    rep(i, 1, N+1){
        cin >> a[i]; 
        G[a[i]].push_back(i);
    }
    rep(i, 1, N+1){
        for(auto g : G[i]){
            if(a[i] == g) ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}