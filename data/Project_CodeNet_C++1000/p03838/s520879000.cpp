#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<char>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pll = pair<ll, ll>;

int main() {
  int x,y; cin>>x>>y;
  if(0<=x && x<y){cout<<y-x;}
  else if(0<y && y<x){cout<<x-y+2;}
  else if(0<=-y && -y<=x){cout<<x+y+1;}
  else if(0<=x && x<=-y){cout<<1-y-x;}
  else if(0<=-x && -x<=y){cout<<1+x+y;}
  else if(0<y && y<=-x){cout<<1-y-x;}
  else if(0<-x && -x<-y){cout<<x-y+2;}
  else {cout<<y-x;}
}