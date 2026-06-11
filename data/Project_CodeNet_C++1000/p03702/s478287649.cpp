#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

const double EPS = 1e-14;
const double PI  = acos(-1.0);


int a, b;
vector<int> h;

bool check(int t) {
  vector<int> v;
  LL cnt = 0;
  for (auto x : h) {
    if (x - (LL)b * (LL)t > 0)
      v.push_back(x - b * t);
  }
  for (auto x : v) {
    cnt += x % (a - b) == 0 ? x / (a - b) : x / (a - b) + 1;
  }
  return cnt <= t;
}

int main(){
  int n;
  scanf("%d %d %d", &n, &a, &b);

  h.resize(n);

  REP (i, n) {
    scanf("%d", &h[i]);
  }

  sort(h.begin(), h.end(), greater<int>());

  int mx = h[0] / b + 2;
  int mn = 1;
  int now = (mx + mn) / 2;
  while (mx - mn > 1) {
    if (check(now)) {
      mx = now + 1;
      now = (now + mn) / 2;
    } else {
      mn = now + 1;
      now = (now + mx) / 2;
    }
  }
  cout << now << endl;
}
