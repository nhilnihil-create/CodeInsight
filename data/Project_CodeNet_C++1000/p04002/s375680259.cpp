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


typedef pair<int, int> p;

int main(){
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);

  vector<p> v;
  int a, b;
  REP (i, n) {
    scanf("%d %d", &a, &b);
    REP (j, 3) REP (k, 3) {
      if (1 <= a - j && a - j <= h - 2 && 1 <= b - k && b - k <= w - 2) {
        v.push_back(make_pair(a - j, b - k));
      }
    }
  }

  sort(v.begin(), v.end());

  LL ans[10];
  REP (i, 10) ans[i] = 0;

  int i = 0;
  int j = 0;
  while (i < int(v.size())) {
    if (v[i].first == v[j].first && v[i].second == v[j].second) j++;
    else {
      ans[j - i]++;
      i = j;
    }
  }

  LL sum = 0;
  REP (i, 10) sum += ans[i];

  ans[0] = (LL)(h - 2) * (LL)(w - 2) - sum;

  REP (i, 10) printf("%lld\n", ans[i]);
}
