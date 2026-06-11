#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
#define brep(i, st, n) for (int i = st; i >= n; --i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};

int main() {
    int n; cin >> n;
    int a[3 * n]; rep(i, 3 * n) cin >> a[i];
    ll ans = -1e15;
    priority_queue<ll, vector<ll>, greater<ll> > v; //小さい順
    priority_queue<ll> vv;
    ll sum = 0;
    rep(i, n) {
        v.push(a[i]);
        sum += a[i];
    }
    ll sum2 = 0;
    brep(i, 3 * n - 1, 2 * n) {
        vv.push(a[i]);
        sum2 += a[i];
    }
    
    ll table[2][3 * n]; rep(i, 2) rep(j, 3 * n) table[i][j] = -1e15;
    table[0][n - 1] = sum;
    table[1][2 * n] = sum2;
    rrep(i, n, 2 * n) {
        sum += a[i];
        v.push(a[i]);
        sum -= v.top();
        table[0][i] = sum;
        //cout << v.top() << endl;
        v.pop(); //一番小さいの消した
        int key = 3 * n - 1 - i;
        
        sum2 += a[key];
        vv.push(a[key]);
        
        sum2 -= vv.top();
        vv.pop(); //忘れてた
        table[1][key] = sum2;
        
    }
    //rep(i, 2) {rep(j, 3 * n) cout << table[i][j] << " "; cout << endl;}
    rep(i, 3 * n - 1) {
        if (table[0][i] == -1e15 || table[1][i + 1] == -1e15) continue;
        ans = max(ans, table[0][i] - table[1][i + 1]);
    }
    cout << ans << endl;
}


