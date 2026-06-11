#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;

  cin >> S;
  for(int i=0;i<S.size()-1;++i){
    char c = S.at(i);
    for(int j=i;j<S.size()-1;++j){
      if(c == S.at(j+1)){
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
  return 0;
}
