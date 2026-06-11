#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
int n,m,a[N],cnt,cur,ans,mx,sgnl,sgnr,tmp;
vector<int> rec[N];
int t[N << 2];
void modify(int l,int r,int val,int x=1,int lp=1,int rp=cnt) {
  if (l > rp || r < lp) return;
  if (l <= lp && rp <= r)
    return (void)(t[x] += val);
  int mid = (lp + rp) >> 1;
  modify(l,r,val,x<<1,lp,mid);
  modify(l,r,val,x<<1|1,mid+1,rp);
}
int query(int p,int x=1,int lp=1,int rp=cnt) {
  if (lp == rp) return t[x];
  int mid = (lp + rp) >> 1;
  if (p <= mid) return query(p,x<<1,lp,mid) + t[x];
  else return query(p,x<<1|1,mid+1,rp) + t[x];
}
signed main() {
  scanf("%lld%lld",&n,&m);
  cnt = 1;
  for (int i = 1 ; i <= n ; ++ i) {
    scanf("%lld",&a[i]);
    if (a[i] < a[i-1]) ++ cnt, ans += m;
    rec[a[i]].push_back(cnt);
    if (i != 1) ans += a[i] - a[i-1];
  }
  tmp = 1;
  for (int i = 1 ; i <= n ; ++ i)
    if (a[i] < a[i-1]) {
      ++ tmp;
      modify(tmp,tmp,m - a[i-1] - 1);
      cur += m - a[i-1] - 1;
    }
  // cerr << ans << endl;
  sgnl = 1;
  for (int i = 1 ; i <= m ; ++ i) {
    int l = 1, r = cnt;
    if (sgnl) ++ l;
    if (sgnr) -- r;
    modify(l,r,1);
    cur += r - l + 1;
    mx = max(mx,cur);
    // cerr << i << "： " << cur << endl;
    for (int j = 0 ; j < (int)rec[i].size() ; ++ j) {
      tmp = query(rec[i][j]);
      cur -= tmp+1;
      modify(rec[i][j],rec[i][j],-tmp-1);
    }
    if (i == a[n]) sgnr = 1, cur ++;
    if (i == a[1]) sgnl = 0;
  }
  ans -= mx;
  printf("%lld\n",ans);
  return 0;
}