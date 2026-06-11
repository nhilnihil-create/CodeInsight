#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  vector<int> t(n);
  rep(i,n){
    cin>>t[i];
  }
  int m;
  cin>>m;
  vector<int> ans(m);
  rep(i,m){
    int p,x;
    cin>>p>>x;
    int c=t[p-1];
    t[p-1]=x;
    rep(j,n){
      ans[i]+=t[j];
    }
    t[p-1]=c;
  }
  rep(i,m){
    cout<<ans[i]<<endl;
  }
}