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

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > v(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].eb(b);
        v[b].eb(a);
    }
    
    vector<pii> reached(100001, {0, 0});
    rep(i, 100001) reached[i].S = i;
    reached[0].F = 1e6;
    
    
    { // 左側 次数3以上でも、テキトーに一つ選ぶ
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            
            for (int nxt : v[now]) {
                if (reached[nxt].F == 0) {
                    q.push(nxt);
                    reached[nxt].F = reached[now].F - 1;
                    break;
                }
            }
        }
    }
    
    {
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            
            for (int nxt : v[now]) {
                if (reached[nxt].F == 0) {
                    q.push(nxt);
                    reached[nxt].F = reached[now].F + 1;
                    break;
                }
            }
        }
    }
    
    sort(all(reached));
    int cnt = 0;
    rep(i, 100001) if (reached[i].F) cnt++;
    out(cnt);
    int flg = 0;
    rep(i, 100001) {
        if (reached[i].F == 0) continue;
        if (flg++) cout << " ";
        cout << reached[i].S + 1;
    }
    cout << endl;
}
