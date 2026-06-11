#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  string s = "1";
  int keta = 10;
  REP(i, 10) {
    cout << "? " << s << endl;
    char c; cin >> c;
    if(c == 'N') {
      keta = i;
      break;
    }
    s.push_back('0');
  }
  if(keta == 10) {
    string tmp = "";
    string ans = "";
    REP(i, 9) {
      tmp.push_back('2');
      if(i == 0) ans.push_back('1');
      else ans.push_back('0');
      cout << "? " << tmp << endl;
      char c; cin >> c;
      if(c == 'Y') {
        cout << "! " << ans << endl;
        return 0;
      }
    }
    cout << "! " << 1000000000 << endl;
    return 0;
  }

  string ans = "";
  for(int i=keta;i>=1;--i) {
    int l, r;
    if(i == keta) {
      l = 0;
      r = 9;
    } else {
      l = -1;
      r = 9;
    }
    while(r - l > 1) {
      int mid = (l + r) / 2;
      string tmp = "";
      REP(j, keta-i) {
        tmp.push_back(ans[j]);
      }
      tmp.push_back(mid + '0');
      REP(j, i) {
        tmp.push_back('9');
      }
      cout << "? " << tmp << endl;
      char c; cin >> c;
      if(c == 'Y') {
        r = mid;
      } else {
        l = mid;
      }
    }
    ans.push_back(r+'0');
  }
  cout << "! " << ans << endl;
}






















