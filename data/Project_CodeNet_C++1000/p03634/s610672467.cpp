#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,c,q,k,x,y,i;
  cin>>n;
  map<pair<int,int>,int64_t> m;
  vector<vector<int>> g(n);
  for(i=0;i<n-1;i++){
    cin>>a>>b>>c;
    a--;b--;
    m[make_pair(a,b)]=c;
    m[make_pair(b,a)]=c;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }
  cin>>q>>k;
  k--;
  vector<int64_t> d(n,-1);
  queue<int> qu;
  d.at(k)=0;
  qu.push(k);
  while(!qu.empty()){
    int u=qu.front();
    qu.pop();
    for(auto z:g.at(u)){
      if(d.at(z)==-1){
        d.at(z)=d.at(u)+m.at(make_pair(u,z));
        qu.push(z);
      }
    }
  }
  for(i=0;i<q;i++){
    cin>>x>>y;
    x--;y--;
    cout<<d.at(x)+d.at(y)<<endl;
  }
}