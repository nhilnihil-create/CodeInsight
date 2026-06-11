#include <bits/stdc++.h>
using namespace std;

vector<int> edge[123456];

template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}


int d(int a){
  int res=0;
  vector<int> v;
  for(int p:edge[a])v.push_back(d(p));
  sort(v.rbegin(),v.rend());
  for(int i=0;i<v.size();i++)chmax(res,v[i]+i);
  return res+1;
}

signed main(){
  int n;cin>>n;
  for(int i=1;i<n;i++){
    int a;cin>>a;a--;
    edge[a].push_back(i);
  }
  cout<<d(0)-1<<endl;
}
