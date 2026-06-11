#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(2e5) + 7;
const int nAlpha = 'z' - 'a' + 1;

int f[N], nxt[N][nAlpha], n, trace[N];
string s;

int DP(int x) {
   if(x > n) return 0;
   if(f[x] != -1) return f[x];
   int& res = f[x];
   res = 2 * n;
   for(int i = 0; i < nAlpha; ++i) {
       if(res > DP(nxt[x][i]) + 1) {
          res = DP(nxt[x][i]) + 1;
          trace[x] = i;
       }
   }
   return res;
}

void Trace(int x) {
    if(x > n) return;
    cout << char(trace[x] + 'a');
    Trace(nxt[x][trace[x]]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> s; n = int(s.size()); s = ' ' + s;
    fill_n(&nxt[0][0], N * nAlpha, 2 * n);
    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < nAlpha; ++j) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i + 1] - 'a'] = i + 1;
    }
    memset(&f, -1, sizeof f);
    DP(0);
    Trace(0);
}
