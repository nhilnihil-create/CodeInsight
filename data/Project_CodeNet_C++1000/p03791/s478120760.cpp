#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long n, lis[100005], cnt[100005], cur, ans;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  FOR (i, 1, n) cin >> lis[i];
  ans = 1;
  cur = 0;
  FOR (i, 1, n - 1) {
  	long long tmp = i - (lis[i] + 1) / 2;
  	cur = max(cur, tmp);
  	cnt[cur]++;
  }
  cur = 1;
  REP (i, n) {
  	cur += cnt[i];
  	ans *= cur;
  	cur--;
  	ans %= mod;
  }
  cout << ans;
}