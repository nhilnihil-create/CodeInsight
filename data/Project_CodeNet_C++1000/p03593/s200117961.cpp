#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int H,W;
  cin>>H>>W;
  map<char,int> m;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++) {
      char c;
      cin>>c;
      m[c]++;
    }
  }
  bool can = true;
  if(H%2==0&&W%2==0){
    for(auto x:m){
      if(x.second%4!=0)can = false;
    }
  }
  else if(H%2==0&&W%2!=0){
    int cnta=0,cntb=0;
    for(auto x:m){
      if(x.second%2==1)cntb++;
      if(x.second%4==2)cnta++;
    }
    if(cntb!=0||cnta>H/2) can = false;
  }
  else if(H%2!=0&&W%2==0){
    int cnta=0,cntb=0;
    for(auto x:m){
      if(x.second%2==1)cntb++;
      if(x.second%4==2)cnta++;
    }
    if(cntb!=0||cnta>W/2) can = false;
  }
  else {
    int cnta = 0,cntb=0,tb=0;
    for(auto x:m){
      if(x.second%2==1){
        cntb++;
        tb+=x.second;
      }
      if(x.second%4==2){
        cnta++;
      }
    }
    if(cntb!=1) can = false;
    else{
      if(tb%4==2)cnta++;
      if(cnta>H/2+W/2) can = false;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}