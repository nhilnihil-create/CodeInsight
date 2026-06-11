#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  ll n,k;
  cin >>n >>k;
  ll q=0;
  vector<pair<int,int>> g(n);
  rep(i,n){
    int a,b;
    cin >> a>>b;
    g[i]=make_pair(a,b);
  }
  sort(g.begin(),g.end());

  rep(i,n){
    q+=g[i].second;
    if(k<=q){cout << g[i].first <<endl; return 0;}
  }
}