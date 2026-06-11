#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  string S;
  cin >> S;
  bool al[26];
  rep(i, 26) al[i] = false;
  
  rep(i, S.size()) al[S[i] - 'a'] = true;
  
  bool a = true;
  rep(i, 26){
    if(!al[i]){
      cout << (char)(i + 'a') << endl;
      a = false;
      break;
    }
  }
  if(a) cout << "None" << endl;
}