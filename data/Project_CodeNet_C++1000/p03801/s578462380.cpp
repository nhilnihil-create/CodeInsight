#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define endl        "\n"
#define P           pair<int, int>

const int mod = 1e9+7;

inline int add(int a, int b) { int res = a + b; if(res >= mod) res -= mod;  return res; }
inline int sub(int a, int b) { int res = a - b; if(res < 0) res += mod; return res;}
inline int mul(int a, int b) { return (a * b)%mod; }

int modpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b%2) ans = mul(ans, a);    
        b /= 2; a = mul(a, a);
    }   return ans;
}

void solve() { 
    int n; cin >> n;
    int a[n];
    map<int, int> cnt;
    map<int, int> fo;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if(fo.find(a[i]) == fo.end()) {
            fo[a[i]] = i+1;
        }
    }
    vector<int> v;
    for(auto it : cnt) {
        v.push_back(it.first);
    }
    int ans[n+1]; memset(ans, 0, sizeof ans);
    reverse(v.begin(), v.end()); 
    int k = v.size();
    int prv = 0;
    int pi = n+1;
    for(int i=0; i<k; i++) {
        int dif = v[i] - (i+1==k ? 0 : v[i+1]);
        int ind = min(fo[v[i]], pi);
        pi = min(pi, ind);
        int tot = cnt[v[i]] + prv;
        prv += cnt[v[i]];
        //cout << v[i] << " " << tot << " " << dif << endl;
        ans[ind] += dif*tot;
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << endl;
    }
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}



