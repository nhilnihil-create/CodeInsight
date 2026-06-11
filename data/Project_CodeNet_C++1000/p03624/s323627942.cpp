#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<bool>vec(26,true);
  for(int i=0; i<S.size();i++){
   vec[S[i]-'a'] = false;
  }
  for(int i=0; i<26; i++){
    if(vec[i] == true){
      cout << (char)(i+'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}
