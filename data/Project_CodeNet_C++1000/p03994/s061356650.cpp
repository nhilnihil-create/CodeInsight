#include <bits/stdc++.h>
using namespace std;
int main () {
  int K;
  string S;
  cin >> S >> K;
  for(int i = 0; i < S.size(); i++){
    if(S.size() - 1 == i){
      S.at(i) = (S.at(i) - 'a' + K) % 26 + 'a';
      break;
    }
    if(26 - (S.at(i) - 'a') <= K && S.at(i) != 'a'){
      K -= 26 - (S.at(i) - 'a');
      S.at(i) = 'a';
    }
  }
  cout << S << endl;
  return 0;
}