#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int g=0,p=0;
  for (int i=0;i<S.size();i++){
    if (S[i]=='g'){
      g++;
    }
    else {
      p++;
    }
  }
  cout << (g-p)/2 << endl;
}