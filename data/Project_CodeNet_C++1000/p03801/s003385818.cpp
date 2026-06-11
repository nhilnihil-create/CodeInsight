#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin>>n;
  map<int,int>sum,ind;
  set<int>exist;
  rep(i,n){
    int a; cin>>a;
    sum[a]++;
    if(!ind.count(a))ind[a]=i;
    exist.insert(a);
  }

  //存在する要素だけを抽出する
  vector<int>x;
  x.push_back(0);
  for(auto p:exist)x.push_back(p);

  //累積和
  int m=x.size();
  for(int i=m-1; i>0; --i){
    sum[x[i-1]]+=sum[x[i]];
  }

  //index修正
  for(int i=m-1; i>0; --i){
    ind[x[i-1]]=min(ind[x[i-1]],ind[x[i]]);
  }

  //大きい方から見ていく
  vector<ll>ans(n);
  for(int i=m-1; i>0; --i){
    ans[ind[x[i]]]+=(ll)(sum[x[i]])*(ll)(x[i]-x[i-1]);
  }
  rep(i,n)cout<<ans[i]<<endl;
}