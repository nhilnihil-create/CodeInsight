#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for(int i=0; i<(S.size()-1)/2+1; i++){
    cout << S[i*2];
  }
}
