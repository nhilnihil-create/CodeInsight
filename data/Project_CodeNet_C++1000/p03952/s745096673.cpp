#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef long double ld;

typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;

constexpr ll MOD = 1e9+7;
constexpr int INF = 1<<30;
constexpr ll  LINF = 1LL<<60;

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define ABS(a,b) ((a)<(b)?(b)-(a):(a)-(b))
#define nbit(n) (1ll<<(n))

// sort(begin(x), end(x), greater<ll>());
// lower_bound(a.begin(), a.end(), val): a[i] ≥ valである最左の位置
// upper_bound(a.begin(), a.end(), val): a[i] > valである最左の位置

// Returns minimum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}

// Returns maximum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

// a = (a+b)%MOD;
void addmod(ll& a, ll b) {
  a = (a+b)%MOD;
}

template <typename T>
void dumpContents(const T& v, const string& msg)
{
  cerr << "### " << msg << " ###\n";
  for (const auto& x : v) {
    cerr << x << " ";
  }
  cerr << endl;
}

struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(20)<<fixed;
    #define endl "\n"
  }
} before_main_function;

// ========== end of template ==========

int N, X;

void fillup(vi& ret) {
  int M = 2*N-1;
  si pool;

  for (int i=1; i<=M; i++) {
    pool.insert(i);
  }

  for (auto x : ret) {
    if (x==0) continue;
    pool.erase(x);
  }

  for (int i=0; i<int(ret.size()); i++) {
    if (ret[i] != 0) continue;

    auto it = pool.begin();
    ret[i] = *it;
    pool.erase(it);
  }

}

int main(int argc, char** argv) {
  cin >> N >> X;

  if (X==1 || X==(2*N-1)) {
    cout << "No" << endl;
    return 0;
  }

  if (N==2) {
    if (X!=2) {
      cout << "No" << endl;
      return 0;
    }

    cout << "Yes\n1\n2\n3" << endl;
    return 0;
  }

  const int M = 2*N-1;
  vi ret(M);

  if (X!=M-1) {
     ret[N-2] = M;
     ret[N-1] = 1; // center
     ret[N]   = X;
     ret[N+1] = M-1;
  } else {
     // X == M-1
     ret[N-2] = 1;
     ret[N-1] = M-1; // X
     ret[N]   = M;
     ret[N+1] = 2;
  }

  fillup(ret);

  cout << "Yes" << endl;
  for (auto x : ret) {
    cout << x << endl;
  }

  return 0;
}
