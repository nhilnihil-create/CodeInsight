#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, count=0;
  vector<bool> num(26);
  string S;
  
  cin >> S;
  
  rep(i,26) num[i] =false;
  
  rep(i,S.size()){
    num[S[i]-'a'] = true;
  }
  
  rep(i,26) {
    if(num[i]==false) {
      cout << (char)(i+'a');
      count =1;
      break;
    }
  }
  
  if(!count) cout << "None";
}