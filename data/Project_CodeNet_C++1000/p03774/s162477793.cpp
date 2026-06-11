#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main(){
  int n,m; cin>>n>>m;
  vector<pii> a(n),c(m);
  rep(i,n)cin>>a.at(i).first>>a.at(i).second;
  rep(i,m)cin>>c.at(i).first>>c.at(i).second;
  int x,y;
  rep(i,n){   
    rep(j,m){    
    int x_ =
      max(a.at(i).first-c.at(j).first
        ,c.at(j).first-a.at(i).first)+
      max(a.at(i).second-c.at(j).second
        ,c.at(j).second-a.at(i).second);
      //cout<<x_<<" ";
    if(j==0){x=x_;y=1;}
    else if(x>x_){x=x_;y=j+1;}
    }
    cout<<y<<endl;
  }
}

