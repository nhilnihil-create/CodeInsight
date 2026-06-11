#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int c = 0;
  int left = 0;
  for (int i = 0; i < N; i++){
    if (S[i] == '('){
      c++;
    } else {
      c--;
      left = max(left, -c);
    }
  }
  c = 0;
  int right = 0;
  for (int i = N - 1; i >= 0; i--){
    if (S[i] == ')'){
      c++;
    } else {
      c--;
      right = max(right, -c);
    }
  }
  for (int i = 0; i < left; i++){
    cout << '(';
  }
  cout << S;
  for (int i = 0; i < right; i++){
    cout << ')';
  }
  cout << endl;
}