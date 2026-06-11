#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1 << 30;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  vvi v(n);
  int a, b;
  REP(i, n-1) {
    cin >> a >> b;
    a--; b--;
    v[a].pb(b);
    v[b].pb(a);
  }

  vi col(n, 0);
  col[0] = 1;
  col[n-1] = -1;
  map<int, int> m;
  queue<int> q;
  q.push(0);
  q.push(n-1);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    REP(i, SZ(v[now])) {
      if(col[v[now][i]] == 0) {
        m[col[now]]++;
        col[v[now][i]] = col[now];
        q.push(v[now][i]);
      }
    }
  }

  if(m[1] > m[-1]) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
  
}
