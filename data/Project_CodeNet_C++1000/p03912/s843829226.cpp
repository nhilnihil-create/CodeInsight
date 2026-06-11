#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int n,m;
int a[100010];
int cnt[100010];
int mod[100010];

void input() {
    cin >> n >> m;
    REP(i,n) {
        cin >> a[i];
        cnt[a[i]]++;
        mod[a[i] % m]++;
    }
}

void solve() {
    int ans = 0;
    ans += mod[0] / 2;
    mod[0] -= ans * 2;
    for (int i = 1; i < m; i++) {
        int add = min(mod[i], mod[m - i]);
        if (i == m - i) {
            mod[i] -= add / 2 * 2;
            ans += add / 2;
            continue;
        }
        mod[i] -= add;
        mod[m - i] -= add;
        ans += add;
        // cout << i << " " << m - i << " " << add << endl;
    }
    for (int i = 0; i < m; i++) {
        if (mod[i] >= 2) {
            for (int j = i; j <= 100000; j += m) {
                if (cnt[j] >= 2) {
                    int add = min(mod[i] / 2, cnt[j] / 2);
                    mod[i] -= add * 2;
                    ans += add;
                    // cout << j << " " << add << endl;
                }
                if (mod[i] < 2) break;
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
