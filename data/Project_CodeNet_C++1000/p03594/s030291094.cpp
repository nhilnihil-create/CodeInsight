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
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz");
ll n, cnt, a, b, c, d, tmp, m, h, w, x, y, sum, k, q;
char now_ans[1500][1500], ans[1500][1500];
ll stx, sty;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> h >> w >> d;
  rep(i, 1200) {
    rep(j, 1200) {
      stx = d * j, sty = d * i;
      if (stx > 1100 || sty > 1100) continue;
      rrep(zx, stx, stx + d) {
        if (zx > 1100) break;
        rrep(zy, sty, sty + d) {
          if (zy > 1100) break;
          if (i % 2 == 0) {
            // G or B
            if (j % 2 == 0)
              now_ans[zy][zx] = 'G';
            else
              now_ans[zy][zx] = 'B';
          } else {
            if (j % 2 == 0)
              now_ans[zy][zx] = 'Y';
            else
              now_ans[zy][zx] = 'R';
          }
        }
      }
    }
  }

  rep(i, 1100) {
    rep(j, 1100) {
      ll ansx, ansy;
      if ((i + j - (w - 1)) % 2 == 1) continue;
      ansy = (i + j - (w - 1)) / 2;
      ansx = i - ansy;
      if (ansx < 0 || ansx >= w || ansy < 0 || ansy >= h) continue;
      ans[ansy][ansx] = now_ans[i][j];
    }
  }
  rep(i, h) {
    rep(j, w) { cout << ans[i][j]; }
    cout << "\n";
  }
  return 0;
}