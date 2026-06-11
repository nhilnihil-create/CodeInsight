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

  int n; cin >> n;
  map<int, int> mp;
  vector<P> v(n);
  vector<int> rem(n);
  queue<int> que;
  REP(i, n) {
    int x; cin >> x;
    x--;
    rem[i] = n - i - 1;
    mp[x] = i+1;
    v[i] = {x, i};
  }
  sort(ALL(v));
  REP(i, n) {
    REP(j, v[i].second) {
      que.push(v[i].second);
    }
  }

  vector<int> cnt(n);

  vi ans;
  bool ok = true;
  REP(i, n*n) {
    if(mp[i]) {
      if(cnt[mp[i]-1] < mp[i] - 1) {
        ok = false;
        break;
      }
      ans.push_back(mp[i]-1);
      REP(j, rem[mp[i]-1]) {
        que.push(mp[i]-1);
      }
    } else {
      if(que.empty()) {
        ok = false;
        break;
      } else {
        ans.push_back(que.front());
        cnt[que.front()]++;
        que.pop();
      }
    }
  }

  if(ok) {
    cout << "Yes" << endl;
    REP(i, n*n) {
      cout << ans[i]+1 << " ";
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }


}






















