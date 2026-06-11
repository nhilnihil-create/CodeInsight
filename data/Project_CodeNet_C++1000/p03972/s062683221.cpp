/*{{{*/
//#include<iostream>
//#include<vector>
//#include<cmath>
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define FOR(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define FORR(i,a,b) for(ll (i)=(b)-1;(i)>=(a);(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl
#define CHMAX(a,b) a=max((a),(b))
#define CHMIN(a,b) a=min((a),(b))
/*}}}*/
int main() {
  ll w,h;
  cin >> w >> h;
  vector<pll> p(w+h);
  REP(i,w) {
    ll pi;
    cin >> pi;
    p[i] = make_pair(pi,0);
  }
  REP(i,h) {
    ll pi;
    cin >> pi;
    p[w+i] = make_pair(pi,1);
  }
  sort(p.begin(),p.end());
  ll n = w+h;
  h++;
  w++;
  ll ans = 0;
  REP(i,n){
    if(p[i].second==1){
      ans += p[i].first * w;
      h--;
    }else{
      ans += p[i].first * h;
      w--;
    }
  }
  cout << ans << endl;

  return 0;
}
