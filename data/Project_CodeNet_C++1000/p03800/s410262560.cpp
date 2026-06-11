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
  int N;
  cin>>N;
  string S;
  cin>>S;
  bool can = false;
  vector<int> ans(N);
  for(int n = 0; n < 4; n++){
    bitset<2> bit(n);
    ans[0]=bit[0];
    ans[1]=bit[1];
    for(int i = 1; i < N-1; i++){
      if(ans[i]==0){
        if(S[i]=='o') ans[i+1]=ans[i-1];
        if(S[i]=='x') ans[i+1]=1-ans[i-1];
      }
      if(ans[i]==1){
        if(S[i]=='o') ans[i+1]=1-ans[i-1];
        if(S[i]=='x') ans[i+1]=ans[i-1];
      }
    }
    int t,s;
    if(ans[0]==0){
      if(S[0]=='o') t=ans[1];
      else t=1-ans[1];
    }
    if(ans[0]==1){
      if(S[0]=='o') t=1-ans[1];
      else t=ans[1];
    }
    if(ans[N-1]==0) {
      if(S[N-1]=='o') s=ans[N-2];
      if(S[N-1]=='x') s=1-ans[N-2];
    }
    if(ans[N-1]==1) {
      if(S[N-1]=='o') s=1-ans[N-2];
      if(S[N-1]=='x') s=ans[N-2];
    }
    if(t==ans[N-1]&&s==ans[0]) {
      can=true;
      break;
    }
  }
  if(can) {
    for(auto x:ans) {
      if(x==0) cout<<'S';
      else cout<<'W';
    }
  }
  else cout<<-1;
  cout<<endl;
}