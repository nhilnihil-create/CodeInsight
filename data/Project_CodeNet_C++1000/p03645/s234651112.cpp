#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,m; cin>>n>>m;
  int a,b;
  vector<int> v1;
  vector<int> vn;
  set<int> s;
  
  rep(i,m){
    cin>>a>>b;
    if(a==1){v1.push_back(b);s.insert(b);}
    if(b==1){v1.push_back(a);s.insert(b);}
    if(a==n){vn.push_back(b);s.insert(a);}
    if(b==n){vn.push_back(a);s.insert(a);}
  }
  if(s.size()<v1.size()+vn.size()){cout<<"POSSIBLE";}
  else{cout<<"IMPOSSIBLE";}
}