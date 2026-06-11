#include<bits/stdc++.h>
using namespace std;
void depth(vector<vector<vector<int>>> &g,vector<int64_t> &d,vector<bool> &c,int v,int64_t vd){
  d.at(v)=vd;
  c.at(v)=1;
  for(auto x:g.at(v)){
    int va=x.at(0);
    int vc=x.at(1);
    if(c.at(va))
      continue;
    depth(g,d,c,va,vd+vc);
  }
  return;
}
int main(){
  int n;
  cin>>n;
  vector<vector<vector<int>>> g(n);
  for(int _=0;_<n-1;_++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    g.at(a).push_back({b,c});
    g.at(b).push_back({a,c});
  }
  int q,k;
  cin>>q>>k;
  k--;
  vector<int64_t> d(n);
  vector<bool> c(n,0);
  depth(g,d,c,k,0);
  for(int _=0;_<q;_++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    cout<<d.at(x)+d.at(y)<<endl;
  }
}