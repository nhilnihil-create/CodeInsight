#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, S;
  cin >> K >> S;
  int kotae = 0;
  for (int X = 0; X <= K; X++){
    int Y_plus_Z = S - X;
    for (int Y = 0; Y <= K; Y++){
      int Z = Y_plus_Z - Y;
      if ((0 <= Z) && (Z <= K)){
        kotae += 1;
      }
    }
  }
  cout << kotae << endl;
}