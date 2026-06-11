#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  char Now = S.at(0);
  int ans = 0;
  
  for (int i = 1; i < S.size(); i++){
    if (Now != S.at(i)){
      ans++;
      Now = S.at(i);
    }
  }
  
  cout << ans << endl;
    
}