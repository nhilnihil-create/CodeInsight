#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<vector<long long>> combinations(int n) {
    auto res = vector<vector<long long>>(n + 1, vector<long long>(n + 1));
    for (int i = 0; i <= n; ++i)res[i][0] = 1;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= i; ++j)
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    return res;
}


// 11,111,1111,...
void hoge() {
    auto C = combinations(1000);
    const int L = 100;
    for (int i = 2; i <= L; ++i) {
        ll res = 0;
        for (int j = 2; j <= i; j += 2) {
            res += C[i][j];
        }
        if (res > 1000000000000ll)break;
        cout << res << endl;
    }
}

// 121,1212,12121,...
void piyo() {
    for (int len = 3; len <= 20; ++len) {
        int cnt = 0;
        
        rep(S, 1 << len) {
            vi v;
            rep(i, len)if (S >> i & 1) {
                if (i & 1)v.push_back(2);
                else v.push_back(1);
            }
            int m = sz(v) / 2;
            bool ok = true;
            rep(i, m) {
                if (v[i] != v[m + i]) {
                    ok = false;
                    break;
                }
            }
            if (ok)cnt++;
        }
        cout << cnt << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;

    int m = -1;
    for (int i = 60; i >= 1; --i) {
        if ((1ll << i)-1 <= N) {
            m = i;
            break;
        }
    }

    ll x = (1ll << m) - 1;
    vi ans(m);
    iota(all(ans), 1);
    
    for (int i = m; i >= 0; --i) {
        if (x + (1ll << i) <= N) {
            ans.insert(ans.begin() + i, ++m);
            x += 1ll << i;
        }
    }

    for (int i = 1; i <= m; ++i)ans.push_back(i);

    m *= 2;
    cout << m << endl;
    rep(i, m) {
        cout << ans[i] << (i != m - 1 ? ' ' : '\n');
    }
}
