#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<char>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pll = pair<ll, ll>;

int main() {
  int n,m,k;
  cin>>n>>m>>k;
  bool b=false;
  rep(x,n+1){
    rep(y,m+1){
      if(n*y+m*x-2*x*y==k){b=true; break;}
    }
  }
  if(b){cout<<"Yes";}
  else{cout<<"No";}
}