#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int cn = 0;
  vector<bool> flag(26);

  cin >> S;
  for(int i=0;i<S.size();++i){
    flag.at(S.at(i) - 'a') = true;
  }
  for(int i=0;i<26;++i){
    if(!flag.at(i)){
      cout << (char)(i + 'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}
