#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string s, t;
  cin >> n >> s >> t;
  for(int i=n;i>=1;i--){
    bool is_ok=true;
    for(int j=0;j<i;j++){
      if(s[n-i+j]!=t[j]){
        is_ok=false;
        break;
      }
    }
    if(is_ok){
      cout << 2*(n-i) + i << endl;
      return 0;
    }
  }
  cout << 2*n << endl;
}

