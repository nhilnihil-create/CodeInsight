#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;
  
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n) cin >> a.at(i) >> b.at(i);

  vector<int> c(m);
  vector<int> d(m);
  rep(i,m) cin >> c.at(i) >> d.at(i);

  rep(i,n){
    ll dist=1000000000;
    int ans=-1;
    rep(j,m){
      ll check = abs(a.at(i)-c.at(j)) + abs(b.at(i)-d.at(j));
      if(check<dist) {ans = j; dist=check;}
    }
    cout<<ans+1<<endl;
  }
}