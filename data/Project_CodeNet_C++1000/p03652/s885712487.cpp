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
int a[310][310];
bool toru[310];

void input() {
    cin >> n >> m;
    REP(i,n) REP(j,m) {
        cin >> a[i][j];
        a[i][j]--;
    }
}

void solve() {
    REP(i,m) toru[i] = 1;
    int mx = n;
    REP(kk,m) {
        int cnt[m] = {};
        REP(i,n) {
            REP(j,m) {
                if (!toru[a[i][j]]) continue;
                cnt[a[i][j]]++;
                break;
            }
        }
        int pos = -1;
        int mmx = 0;
        REP(i,m) {
            if (cnt[i] > mmx) {
                mmx = cnt[i];
                pos = i;
            }
        }
        toru[pos] = 0;
        mx = min(mx,mmx);
    }
    cout << mx << endl;
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
