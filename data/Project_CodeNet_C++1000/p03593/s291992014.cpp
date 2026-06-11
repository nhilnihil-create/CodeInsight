#include<bits/stdc++.h>
using namespace std;
signed main(){
  int h,w;
  cin>>h>>w;
  map<char,int> m;
  string s;
  for(int i=0;i<h;++i){
    cin>>s;
    for(auto c:s)++m[c];
  }
  for(auto &p:m)p.second%=4;
  int tw=h%2*w/2+w%2*h/2, on=h%2&&w%2;
  
  cerr<<tw<<" "<<on<<"\n";
  for(auto p:m){
    if(p.second%4==2)--tw;
    if(p.second%4==1)--on;
  }
  cerr<<tw<<" "<<on<<"\n";
  if(tw>=0&&on==0)cout<<"Yes";
  else cout<<"No";
}