#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 1000000007;
const lli e3 = 1 << 13;
const lli INF = 1ll << 62;

lli n;
lld x[e5];
lli m,k;
lli a[e5];
lld dy[e5];
lld dy_[e5];
lli s[e5];
lli s_[e5];

int main(){
  cin >> n;
  for(lli i = 1;i <= n;i++) cin >> x[i];
  cin >> m >> k;
  for(lli i = 1;i <= m;i++) cin >> a[i];
  for(lli i = 1;i < n;i++){
    dy[i] = x[i+1]-x[i];
  }
  iota(s,s+n,0ll);
  for(lli i = 1;i <= m;i++){
    swap(s[a[i]],s[a[i]-1]);
  }
  for(lli b = 1;b <= k;b <<= 1){

    if((b&k) != 0){
      for(lli i = 1;i < n;i++){
        dy_[i] = dy[s[i]];
      }
      swap(dy,dy_);
    }
    for(lli i = 1;i < n;i++){
      s_[i] = s[s[i]];
    }
    swap(s,s_);

  }
  lli point = x[1];
  for(lli i = 1;i <= n;i++){
    cout << point << endl;
    point = point + dy[i];
  }

}
