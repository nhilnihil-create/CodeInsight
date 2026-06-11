#include <bits/stdc++.h>
using namespace std;

int main(){
  string a;
  cin >> a;
  string ans = "";
  for(int i = 0; i < a.size(); i ++){
      if(a[i] == ','){
          ans += ' ';
          continue;
      }
      ans += a[i];
  }
  
  cout << ans;
  return 0;
}
