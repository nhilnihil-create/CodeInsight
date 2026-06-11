#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  int marker[26] = {0};
  for(auto x : s){
    marker[x-'a']++;
  }
  for(int i = 0;i<26;i++){
    if(marker[i] % 2 != 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}