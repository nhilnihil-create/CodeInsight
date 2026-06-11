#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  string s; cin >>s;
  int n = s.size();
  int cnt = 0;
  char cur = s[n-1];
  for(int i = n-1; 0<=i; i--){
    if(s[i]!=cur){
      cnt++;
      cur = s[i];
    }
  }
  cout << cnt << endl;
  return 0;
}