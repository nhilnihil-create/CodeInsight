#include <bits/stdc++.h>
using namespace std;
#define forr(i,m,n) for (int i=(m); i<=(n); i++)
#define forv(i,m,n) for (int i=(m); i>=(n); i--)
#define forall(it,p) for (auto it = p.begin(); it != p.end(); ++it)
#define R 1000000007
#define DBG 1
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

#define MAXN 100002
int a[MAXN];

vector< vector<int> > dst;

int dep(int v) {
  if (dst[v].size()==0) return 0;
  vector<int> a;
  for(auto u: dst[v]) a.push_back(dep(u));
  sort(a.begin(),a.end());
  int mx = 0;
  int m = a.size();
  forr(i,0,m-1) mx = max(mx, a[i]+m-i);
  return mx;
}

int main() {
  int n,x;
  cin >> n;
  dst.resize(n+1);
  forr(i,2,n) {
    cin >> x;
    dst[x].push_back(i);
  }
  cout << dep(1) << endl;
}
