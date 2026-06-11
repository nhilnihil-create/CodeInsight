#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;

int main(){
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  ll dx = tx - sx;
  ll dy = ty - sy;
  string u = "U", d = "D", l = "L", r = "R";
  string ans;
  rep(i,dy){
    ans.append(u);
  }
  rep(i,dx){
    ans.append(r);
  }
  rep(i,dy){
    ans.append(d);
  }
  rep(i,dx+1){
    ans.append(l);
  }
  rep(i,dy+1){
    ans.append(u);
  }
  rep(i,dx+1){
    ans.append(r);
  }
  ans.append(d);
  ans.append(r);
  rep(i,dy+1){
    ans.append(d);
  }
  rep(i,dx+1){
    ans.append(l);
  }
  ans.append(u);
  cout << ans << endl;
  return 0;
}