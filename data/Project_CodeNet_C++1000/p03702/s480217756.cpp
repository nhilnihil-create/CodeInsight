#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll>h(n);
  rep(i,n)cin >> h[i];
  ll ng = 0,ok = 1e9;
  while(abs(ng - ok) > 1){
    ll mid = (ok + ng) / 2;
    bool can = false;
    ll tmp = 0;
    rep(i,n){
      tmp += (max((ll)0,h[i] - b * mid) + a - b - 1) / (a - b);
    }
    if(tmp <= mid)can = true;
    if(can)ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}
