
#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,m; cin>>n>>m;
  set<int> s;
  s.insert(0);
  int sum=0;
  rep(i,m){
    int a; cin>>a;    
    sum+=a;
    set<int> t;  t=s;
    for(int j: t){
      s.insert(j+a);
    }
  }
  int x=0;
  for(int i:s){
    if(i<=sum/2){x=max(x,i);}
  }
  cout<<max(0,sum-x-x-1)<<endl;
}