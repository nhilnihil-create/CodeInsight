#include <bits/stdc++.h>  
using namespace std;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using graph =vector<vector<int>>;
using ll = long long int;

int  main(){
  int n,t;cin>>n>>t;
  vector<int> v(n),vec(n-1);
  int x=t;
  rep(i,n){cin>>v[i];}
  rep(i,n-1){
    vec[i]=v[i+1]-v[i];
    x+=min(t,vec[i]);
  }
  cout<<x;
}