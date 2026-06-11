#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using P=pair<ll ,ll>;

int main(){
  int n,m;
  std::cin >> n>>m;
  std::vector<P> s;
  std::vector<P> c;
  rep(i,n){
    int t1,t2;
    std::cin >> t1>>t2;
    s.push_back(P(t1,t2));
  }
  rep(i,m){
    int t1,t2;
    std::cin >> t1>>t2;
    c.push_back(P(t1,t2));
  }


  rep(i,n){
    ll cost=100100100100100;
    int p=0;
    ll nx=s[i].first;
    ll ny=s[i].second;
    rep(j,m){
      ll now=abs(nx-c[j].first)+abs(ny-c[j].second);
      if(cost>now){
        cost=now;
        p=j+1;
      }
    }
    std::cout << p<< '\n';
  }

  return 0;
}
