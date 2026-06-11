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
ll n, cnt, ans, a, b, c, d, tmp, m, h, w, x[ohara], y, sum, k, q;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  rep(i, n) cin >> x[i];
  //奇数に配置すると嬉しいよね 1,3,5.....ね
  // 1,2はコーナーケースですよねえ
  if (x[0] == 1 && x[1] == 2) {
    ll want = 3;
    cnt = 1;
    ans = 2;
    rrep(i, 2, n) {
      if (want <= x[i])
        cnt++, want += 2;
      else {
        ans *= (cnt + 1);
        ans %= MOD;
      }
    }
    rrep(i, 1, cnt + 1) {
      ans *= i;
      ans %= MOD;
    }
    Cout(ans);
  } else {
    ll want = 1;
    cnt = 0;
    ans = 1;
    rep(i, n) {
      if (want <= x[i])
        cnt++, want += 2;
      else {
        ans *= (cnt + 1);
        ans %= MOD;
      }
    }
    rrep(i, 1, cnt + 1) {
      ans *= i;
      ans %= MOD;
    }
    Cout(ans);
  }
  return 0;
}