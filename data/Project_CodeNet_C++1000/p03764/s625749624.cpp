#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;



int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> x(n),y(m);
  rep(i,n) cin >> x.at(i);
  rep(i,m) cin >> y.at(i);
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  vector<ll> a(n-1),b(m-1);
  rep(i,n-1){
    a.at(i)=x.at(i+1)-x.at(i);
  }
  rep(i,m-1){
    b.at(i)=y.at(i+1)-y.at(i);
  }
  ll xx=0,yy=0;
  rep(i,n-1){
    xx=(xx+a.at(i)*(i+1)*(n-1-i))%MOD;
  }
  rep(i,m-1){
    yy=(yy+b.at(i)*(i+1)*(m-1-i))%MOD;
  }
  //cout << xx << " " << yy << endl;
  cout << xx*yy%MOD << endl;
  }