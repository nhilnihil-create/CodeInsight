#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> d(1000010);
    d[0] = 0;
    d[1] = d[2] = d[3] = 1;
    for (int i = 0;i < n;++i) {
        if (i > 2) d[i+1] = (d[i]+d[i-1]+d[i-3])%mod;
        if (i < n-1) (ans += d[i+1]*(n-1)%mod*(n-1)%mod) %= mod; 
        if (i < n-2) (ans += d[i+1]*(i+2)) %= mod;
        else (ans += d[i+1]*(i+1)) %= mod;
    }
    cout << ans << endl;
}