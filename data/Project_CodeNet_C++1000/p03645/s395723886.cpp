#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,m;
  cin >>n>>m;
  vector<pair<int,int>> a(m);
  vector<bool> ans(n,false);
  rep(i,m){
    int c,d;
    cin >>c>>d;
    a.at(i)=make_pair(c,d);
    if(c==1){
      ans.at(d-1)=true;
    }
  }
  sort(a.begin(),a.end());
  for( auto p:a){
    int d=p.first;
    int e=p.second;
    if(ans.at(d-1)==true && e==n){
      cout <<"POSSIBLE";
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
}
  