#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
struct Segment_Min {
private:
  int n;
  vector<int> node;
public:
  Segment_Min(vector<int> v) {
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, INF);
    for(int i=0; i<sz; i++) node[i+n-1] = v[i];
    for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
  }
  void update(int x, int val) {
    x += (n - 1);
    node[x] = val;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = min(node[2*x+1], node[2*x+2]);
    }
  }
  int getmin(int a, int b, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    if(r <= a || b <= l) return INF;
    if(a <= l && r <= b) return node[k];
    int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
    int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, x;
  cin >> N >> x;
  vector<int> a(2*N);
  REP(i, N) cin >> a[i];
  REP(i, N) a[N+i] = a[i];
  Segment_Min seg(a);
  lint ans = 1e18;
  REP(k, N+1) {
    lint tmp = (lint)k*(lint)x;
    REP(i, N) tmp += (lint)seg.getmin(N+i-k, N+i+1);
    if(tmp < ans) ans = tmp;
  }
  cout << ans << endl;
}