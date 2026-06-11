#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

int main() {
  int n,m;  cin>>n>>m;
  vector<int> v(n+1,0), vec(n+1,1);
  v[1]=1;
  rep(i,m){
    int a,b; cin>>a>>b;
    if(v[a]==1){
      v[b]=1;
    }
    vec[a]--;vec[b]++;
    if(vec[a]==0){v[a]=0;}
  }
  int c=0;
  rep(i,n){
    if(v[i+1]==1 &&vec[i+1]!=0){c++;}
  }
  cout<<c;
}