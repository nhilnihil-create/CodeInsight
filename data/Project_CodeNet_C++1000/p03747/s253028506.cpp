#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}


typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


int main() {
  ll n, l, t;
  cin >> n >> l >> t;
  vl x(n), w(n);
  bool w1 = false, w2 = false;
  rep (i, n) {
    cin >> x[i] >> w[i];
    if (w[i] == 1) w1 = true;
    else w2 = true;
  }

  // もしすれ違うならi番目のアリはx2[i]
  using P = pair<ll, pii>;
  vector<P> x2(n);
  rep (i, n) {
    if (w[i] == 1) {
      x2[i].first = (x[i] + t) % l;
    }
    else {
      x2[i].first = (x[i] - t) % l;
      x2[i].first = (x2[i].first + l) % l;
    }
    x2[i].second.first = w[i];
    x2[i].second.second = i;
  }

  if (!w1 || !w2) {
    rep (i, n) {
      cout << x2[i].first << endl;
    }
    return 0;
  }

  int now;
  int cnt2 = 0;
  rrep (i, n) {
    if (w[i] == 1) now = i;
    else cnt2++;
  }

  //DEBUG(now);
  ll col = 0;
  col += (ll)cnt2 * (t / l) * 2;
  t %= l;
  //DEBUG(col);

  pll lr(x[now], x[now] + t);
  //DEBUG(lr);
  rep (i, n) {
    if (w[i] == 1) continue;
    int s = x[i];
    if (s < x[now]) s += l;
    double f = (x[now] + s) / 2.0;
    if (f < x[now] + t) col++;
    f += l / 2.0;
    if (f < x[now] + t) col++;
  }
  //DEBUG(col);
  
  int af = (now + col) % n;
  sort(all(x2));
  vl ans(n);
  int st;
  rep (i, n) {
    if (x2[i].second.second == now) {
      st = i;
      break;
    }
  }
  for (int i = -1; i != st; i = (i + 1) % n) {
    if (i == -1) i = st;
    ans[af] = x2[i].first;
    af = (af + 1) % n;
  }
  
  rep (i, n) {
    cout << ans[i] << endl;
  }
}
