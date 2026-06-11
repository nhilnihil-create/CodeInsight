#include <bits/stdc++.h>
using namespace std;

int main(){
  string w;
  cin >> w;
  for (char c = 'a'; c != '{'; c = char(c + 1)){
    int cnt = 0;
    for(int i = 0; i < w.size(); i++){
      if(w.at(i) == c){
        cnt++;
      }
    }
    if(cnt % 2 == 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}