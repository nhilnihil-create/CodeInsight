#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n-1);
    rep(i, n) cin >> a[i];
    rep(i, n-1){
        if(a[i+1] - a[i] == 0) b[i] = 0;
        else if(a[i+1] - a[i] > 0) b[i] = 1;
        else b[i] = -1;
    }
    // rep(i, n-1) cout << b[i] << endl;               1 2 3 4 3 2 2 2 3 4
    ll ans = 1, state = -2;                         //  1 1 1 - - 0 0 1 1
    rep(i, n-1){
        // cout << state << endl;
        if(b[i] == 0) continue;
        if(state == -2){
            state = b[i];
            continue;
        }
        if(b[i] == 1 && state == -1){
            ans++;
            state = -2;
        }
        else if(b[i] == -1 && state == 1){
            ans++;
            state = -2;
        }
    }
    cout << ans << endl;
}