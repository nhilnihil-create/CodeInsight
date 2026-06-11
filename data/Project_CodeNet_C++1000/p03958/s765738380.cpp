#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    int mx = 0, id = 0;
    rep(i,t){
        cin >> a[i];
        if(mx < a[i]){
            id = i;
            mx = a[i];
        }
    }
    int rest = k - mx;
    int ans = 0;
    if(mx > rest+1){
        mx -= rest;
        ans = mx - 1;
    }
    cout << ans << endl;
	return 0;
}