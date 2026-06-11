#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,m;
  cin>>n>>m;
  
  vector<int>a(m);
  vector<int>b(m);
  
  rep(i,m)cin>>a[i]>>b[i];
  vector<int>city(n);
  rep(i,m){
    city[a[i]-1]++;
    city[b[i]-1]++;
  }
  
  rep(i,n)cout<<city[i]<<endl;
  return 0;
}