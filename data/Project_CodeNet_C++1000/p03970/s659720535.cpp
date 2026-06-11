#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  string T = "CODEFESTIVAL2016";
  
  int count = 0;
  for (int i = 0; i < N; i++){
    if (S.at(i) != T.at(i)){
      count++;
    }
  }
  cout << count << endl;
}