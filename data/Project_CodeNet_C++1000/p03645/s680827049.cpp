#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> v[n];
  rep(i,0,m){
    int a,b;
    cin>>a>>b;
    v[a-1].push_back(b-1);
    v[b-1].push_back(a-1);
  }
  bool p=false;
  rep(i,0,v[0].size()){
    int q=v[0][i];
    rep(j,0,v[q].size()){
      int r=v[q][j];
      if(r==n-1) p=true;
    }
  }
  if(p) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}