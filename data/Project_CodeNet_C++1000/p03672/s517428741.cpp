#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for(int i=0; i > -1; i++){
    S.pop_back();
    string x = S.substr(0,S.size()/2);
    string y = S.substr(S.size()/2,S.size()-1);
    if(x == y){
      cout << S.size() << endl;
      return 0;
    }
  }
}
