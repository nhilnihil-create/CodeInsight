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

int n;
map<int,int> mp;

void input() {
    cin >> n;
    REP(i,n) {
        int k;
        cin >> k;
        mp[k]++;
    }
}

void solve() {
    if (sz(mp) > 2) {
        cout << "No" << endl;
        return;
    }
    if (sz(mp) == 1) {
        int num = (*mp.begin()).fi;
        cout << (num * 2 <= n || num == n - 1? "Yes":"No") << endl;
        return;
    }
    auto it = mp.begin();
    int k1 = (*it).fi;
    int num1 = (*it).se;
    it++;
    int k2 = (*it).fi;
    int num2 = (*it).se;
    int different_nums = k1 - num1 + 1;
    if (different_nums < 1 || different_nums * 2 > num2) {
        cout << "No" << endl;
        return;
    }
    if (k2 != k1 + 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
