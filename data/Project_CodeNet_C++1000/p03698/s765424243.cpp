#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  for(int i = 0; i < S.size()-1; i++){
    for(int j = i+1;j<S.size(); j++){
      if(S.at(i) == S.at(j)){
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
}