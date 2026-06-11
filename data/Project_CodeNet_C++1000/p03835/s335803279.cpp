#include <bits/stdc++.h>
using namespace std;
int main() {
  int K,S;
  cin >> K >> S;
  long long count = 0;
  for (int i = 0; i <= K; i++) {
    if (S-i >= K){
      count += max(2*K + i + 1 - S,0);
    }
    else {
      count += max(S - i + 1,0);
    }
  }
  cout << count << endl;
}