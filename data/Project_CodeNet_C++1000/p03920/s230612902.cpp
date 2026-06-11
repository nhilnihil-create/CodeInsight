#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; i < (n); i++)

int main(){
  
  int n, s = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    s += i;
    if(s >= n){
      for(int j = 1; j <= i; j++){
        if(j == s - n) continue;
        cout << j << endl;
      }
      return 0;
    }
  }
}