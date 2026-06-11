#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;

ll ans=0;

void plu(string s){
  string n="";
  rep(i,s.size()){
    if(s[i]=='+'){
      ans+=stoll(n);
      n="";
    }else{
      n+=s[i];
    }
  }
  ans+=stoll(n);
}

void bfs(int c,string s){
  if(c==0){
    plu(s);
    return;
  }
  bfs(c-1,s);
  if(c>0){
    s.insert(c,"+");
    bfs(c-1,s);
  }
}

int main() {
  string s;
  cin >>s;
  bfs(s.size()-1,s);
  cout <<ans<<endl;
}