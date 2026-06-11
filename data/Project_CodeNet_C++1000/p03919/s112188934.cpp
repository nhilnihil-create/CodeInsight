#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

ll mod = 1e9 + 7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;
  string s;
  REP(i, h){
    REP(j, w){
      cin >> s;
      if(s == "snuke"){
        cout << char('A' + j) << i + 1 << endl;
        return 0;
      }
    }
  }
}
