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
  int n, m;
  cin >> n >> m;
  vi a(m);
  rep (i, m) {
    cin >> a[i];
  }

  if (m <= 2) {
    vi b = a;
    if (b.size() == 1) b.push_back(0);
    b[0]--; b.back()++;
    if (b[0] == 0) b.erase(b.begin());
    
    rep (i, m) cout << a[i] << " ";
    cout << endl;
    
    cout << b.size() << endl;
    rep (i, b.size()) {
      cout << b[i] << " ";
    }
    cout << endl;
    return 0;
  }
    
    

  int cnt = 0;
  rep (i, m) {
    cnt += a[i] % 2;
  }

  if (cnt > 2) {
    cout << "Impossible" << endl;
    return 0;
  }

  vi b_odd, b_even;
  rep (i, m) {
    if (a[i] % 2) b_odd.push_back(a[i]);
    else b_even.push_back(a[i]);
  }
  
  vi b;
  if (b_odd.size()) {
    b.push_back(b_odd[0]);
    b_odd.erase(b_odd.begin());
  }
  rep (i, b_even.size()) b.push_back(b_even[i]);
  if (b_odd.size()) {
    b.push_back(b_odd[0]);
    b_odd.erase(b_odd.begin());
  }
  
  rep (i, b.size()) {
    cout << b[i] << " ";
  }
  cout << endl;

  b[0]--;
  b.back()++;
  if (b[0] == 0) b.erase(b.begin());
  cout << b.size() << endl;
  rep (i, b.size()) {
    cout << b[i] << " ";
  }
  cout << endl;
    
  
}
