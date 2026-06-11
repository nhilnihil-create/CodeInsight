#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl; }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())
ll pow(ll a, int b) {return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1;}
ll nck(int n, int k) { ll ret = 1; rep(i, k) {ret *= n - i; ret /= i + 1; } return ret; } // n <= 60
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n, m;
    cin >> n >> m;
    list<int> li[n];
    map<pii, int> mp; // あるスポーツ消したとき、O(1)で表のその人の消したい
    rep(i, n) rep(j, m) { int a; cin >> a; li[i].eb(a); mp[pii{i, a}] = j; }
    
    int deleted[n][m];
    fill_n(*deleted, n * m, 0);
    
    int ans = inf;
    rep(i, m) {
        int table[m + 1];
        fill_n(table, m + 1, 0);
        rep(j, n) table[*li[j].begin()]++;
        // rep(j, m) cout << table[j + 1] << " "; cout << endl;
        int tmp = 0;
        rep(j, m) chmax(tmp, table[j + 1]);
        chmin(ans, tmp);
        
        int mmax = -1, id = 0;
        rep(j, m) {
            if (mmax < table[j + 1]) {
                mmax = table[j + 1];
                id = j + 1;
            }
        }
        
        if (i == m - 1) continue;
        rep(j, n) deleted[j][mp[pii{j, id}]] = 1;
        rep(j, n) while (deleted[j][mp[pii{j, *li[j].begin()}]]) li[j].erase(li[j].begin());
        
    }
    out(ans);
}

