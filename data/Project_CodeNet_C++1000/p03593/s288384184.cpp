#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int w,h;cin>>w>>h;
  map<char, int> m;
  rep(i,w)rep(j,h){
    char t;cin>>t;
    m[t]++;
  }

  bool f=true;
  if(h%2==0 && w%2==0){
    for(auto p:m){
      if(p.second%4){f=false;break;}
    }
  }else if(h%2 && w%2){
    map<int,int> c;
    for(auto p:m)c[p.second%4]++;
    if(c[1]+c[3]!=1)f=false;
    if(c[2] > w/2+h/2)f=false;
  }else{
    int even = w;
    if(h%2==0)even=h;

    map<int,int> c;
    for(auto p:m)c[p.second%4]++;

    if(c[1] || c[3] || c[2]>even/2)f=false;
  }
  
  if(f)cout<<"Yes";
  else cout<<"No";

  return 0;
}
