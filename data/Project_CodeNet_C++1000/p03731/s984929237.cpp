#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fo(x, n) for(int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector <int> vi;
const int MOD = 1e9 + 7;

void solve(){
    ll n, t;
    ll ans = 0;
    cin >> n >> t;
    ll last = 0, prev = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(last > x){
            ans -= last - x;
        }
        prev = x;
        last = x + t;
        ans += last - prev;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
    //cin >> T;
    fo(1, T){
        solve();
    }
}