#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int INF = 0x3f3f3f3f; constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define db(x) { cerr << #x << " = " << x << endl; }
template<class RIt> void dbarr(RIt frs, RIt lst){ cerr << "arr: "; for(int i = 0; i < (int)(lst-frs); i++) cerr << frs[i] << " \n"[i==(int)(lst-frs)-1]; }
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define fs first
#define sn second

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int& v : a) cin >> v;
    unordered_map<int,int> f;

    vector<int> sides;

    for(int v : a){
        f[v]++;
        if(f[v] >= 2 && f[v] % 2 == 0){
            sides.eb(v);
        }
    }
    if(sides.size() <= 1){
        cout << "0\n";
        return 0;
    }

    sort(all(sides),greater<>());
    cout << 1ll*sides[0]*sides[1] << "\n";
}

