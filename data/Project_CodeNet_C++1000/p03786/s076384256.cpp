#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(ALL(a));

  vector<ll> sum(n);
  ll s = 0;
  REP(i,n){
    s += a[i];
    sum[i] = s;
  }

  int cnt = 0;
  REP(i,n-1){
    if(sum[i]*2 >= a[i+1]) cnt++;
    else cnt = 0;
    //cout << cnt << " ";
  }
  //cout << endl;

  //if(cnt == 0) cout << 1 << endl;
  cout << cnt+1 << endl;

  //
  // // for(auto x: a) cout << x << endl;
  // for(auto x: sum) cout << x << endl;
  //
  // int f = upper_bound(ALL(sum), *a.rbegin()) - sum.begin();

  //cout << n - f + 1 << endl;

  return 0;
}
