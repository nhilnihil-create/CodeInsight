#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
// typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 998244353;
const lli e3 = 1 << 12;

lli n,l,t;
lli x[e5],w[e5];
lli reverse_ants;
lli cross_ants;
lli ans[e5];

int main(){
  cin >> n >> l >> t;
  for(lli i = 0;i < n;i++) cin >> x[i] >> w[i];
  for(lli i = 0;i < n;i++){
    if(w[i] != w[0]){
      reverse_ants++;
      if(w[0] == 1){
        if((x[i]-x[0]+l)%l-t%l <= (t%l)) cross_ants++;
        if(2*(t%l)-((x[i]-x[0]+l)%l) >= l) cross_ants++;
      }else{
        if((x[0]-x[i]+l)%l-t%l <= (t%l)) cross_ants++;
        if(2*(t%l)-((x[0]-x[i]+l)%l) >= l) cross_ants++;
      }
    }

  }
  cross_ants += reverse_ants*(t/l)*2;
  cerr << t/l << " " << cross_ants << endl;
  for(lli i = 0;i < n;i++){
    if(w[i] == 1) x[i] = (x[i]+t)%l;
    else{
      x[i] -= t;
      if(x[i] < 0) x[i] += l*((-x[i])/l);
      x[i] = (x[i]+l)%l;
    }
  }
  lli hoge = x[0];
  for(lli i = 0;i < n;i++){
    x[i] = (x[i]-hoge+l)%l;
  }
  for(lli i = 1;i < n;i++){
    if(x[i] == 0){
      if(w[i] == 2) x[i] += l;
    }
  }
  sort(x,x+n);
  for(lli i = 0;i < n;i++) x[i] = (x[i]+hoge)%l;
  lli start;
  if(w[0] == 1) start = cross_ants%n;
  else start = (n*(cross_ants/n)-cross_ants+n)%n;
  for(lli i = 0,j = start;i < n;i++,j = (j+1)%n){
    ans[j] = x[i];
  }

  for(lli i = 0;i < n;i++){
    cout << ans[i] << endl;
  }

}
