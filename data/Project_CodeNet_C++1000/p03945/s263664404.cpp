#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int count = 0;
  for(int i=1; i<S.size(); i++){
    if(S[i-1] != S[i]) count++;
  }

  cout << count << endl;
}