#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >> S;

    vector<int> Chr(27,0);
    string alph = "abcdefghijklmnopqrstuvwxyz";
  
    for (int i = 0; i < S.size(); i++){
      for (int j = 0; j < 26 ; j++){
      if (S.at(i) == alph.at(j)) Chr.at(j)++;
      }       
    }
  
    string ans = "None";
    for (int i=0; i<26; i++){
      if (Chr.at(i) == 0){
        ans = alph.at(i);
        break;
      }
    }
    cout << ans << endl;
}
