#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  string s,t;
  cin >>n >>s >>t;
  int ans = 0;
  for(int i = n; 0<=i; i--){
    if(s.substr(n-i)==t.substr(0,i)){
      ans = 2*n-i;
      break;
    }
  }
  cout << ans << endl;
  return 0; 
}