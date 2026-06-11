#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  
  vector<char> S(N)
  ;for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  
  int countb = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'b' && countb < B){
      S.at(i) = 'a';
      countb++;
    }
  }
      
  int counta = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'a' && counta < A + B){
      counta++;
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}