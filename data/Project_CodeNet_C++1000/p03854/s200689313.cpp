#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, j, k;
  bool judge=false;
  string S, test;
  
  cin >> S;
  
  string divide[4] = {"dream","dreamer","erase","eraser"};
  
  rep(i,4) reverse(divide[i].begin(),divide[i].end());
  reverse(S.begin(),S.end());
  
  for(i=0;i<S.size();){
    judge=false;
    rep(j,4){
      test=divide[j];
      if (S.substr(i,test.size())==test){
        i+=test.size();
        judge=true;
        break;
      }
    }
    
    if(!judge){
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
  
}