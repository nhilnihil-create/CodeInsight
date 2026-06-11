#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  std::vector<std::string>s1(N/2);
  std::vector<std::string>s2(N/2);
  s1.at(0) = S.at(0);
  s2.at(0) = S.at(1);
  for (int i = 1; i < (N-1)/2; i++) {
    s1.at(i) = s1.at(i-1) + S.at(i);
    s2.at(i) = S.at(i+1);
    for (int j = 0; j < i; j++) {
      s2.at(i) += S.at(i+j+2);
    }
  }
  int M;
  for (int i = 0; i < (N-1)/2; i++) {
    if (s1.at(i) == s2.at(i)){
      M = (i+1)*2;
    }
  } 
  cout << M << endl;
}