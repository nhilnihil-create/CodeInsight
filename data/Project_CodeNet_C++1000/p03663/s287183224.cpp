#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
#define int ll

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int n;

bool query(string s) {
  cout << "? " << s << endl;
  string ret;
  cin >> ret;
  if(ret == "Y") return true;
  else return false;
  /*if((stoll(s) <= n && s <= to_string(n))
    || (stoll(s) > n && s > to_string(n))) {
    cout << "Yes" << endl;
    return true;
  }
  cout << "No" << endl;
  return false;*/
}

signed main(void)
{
  // cin >> n;
  // int nn;
  // cin >> nn;
  // REP(cc, nn) {
  // n = cc+1;
  // Nが何桁か特定する
  int cnt = 1, num = -1;
  REP(i, 10) {
    if(!query(to_string(cnt))) {
      num = i+1;
      break;
    }
    cnt *= 10;
  }
  // 1, 10, 100, … の判定
  if(num == -1) {
    string s = "9";
    bool flag = false;
    REP(i, 9) {
      if(query(s)) {
        cout << "! 1" + string(i, '0') << endl;
        // flag = true;
        // break;
        return 0;
      }
      s += '9';
    }
    // if(flag) continue;
    cout << "! 1000000000" << endl;
    return 0;
  }

  //i桁目をにぶたんで決定
  string ans(num, '0');
  REP(i, num-1) {
    int l = 0, r = 10;
    while(r-l>1) {
      int m = (l+r)/2;
      // cout << l << " " << m << " " << r << endl;
      string t = ans;
      t[i] = char(m + '0');

      if(query(t)) {
        r = m;
      } else {
        l = m;
      }
    }
    ans[i] = (char)(l+'0');
  }

  ans = ans.substr(0, ans.size()-1);
  cout << "! " << stoll(ans) + 1 << endl;
  // if(cc+1 != stoi(ans) + 1) cout << "///" << cc+1 << endl;
  // }

  return 0;
}
