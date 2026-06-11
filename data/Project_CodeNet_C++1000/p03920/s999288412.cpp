#pragma target("avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, a, b, c, d, tmp, m, h, w, x, y, sum, k, q;
ll rui[10000000 + 10];
V ans;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  rui[1] = 1;
  rrep(i, 2, n + 1) { rui[i] += rui[i - 1] + i; }
  ll now = n;
  rrep(i, 1, n + 1) {
    tmp = n - i;
    if (rui[i - 1] >= tmp) {
      ans.p_b(i);
      tmp = i;
      now -= i;
      break;
    }
  }
  rrrep(i, tmp - 1, 1) {
    if (now == 0) break;
    if (now >= i) {
      now -= i;
      ans.p_b(i);
    }
  }
  rep(i, Size(ans)) Cout(ans[i]);
  return 0;
}