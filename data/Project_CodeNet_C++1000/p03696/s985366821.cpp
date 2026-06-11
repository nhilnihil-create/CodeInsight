#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  string S,left,right;
  cin>>N>>S;
  stack<char> brackets;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') {
      brackets.push('(');
    } else if (brackets.empty()) {
      brackets.push(')');
    } else {
      if (brackets.top() == '(') {
        brackets.pop();
      } else {
        brackets.push(')');
      }
    }
  }
  while (!brackets.empty()) {
    if (brackets.top() == '(') {
      right.push_back(')');
    } else {
      left.push_back('(');
    }
    brackets.pop();
  }
  cout<<left<<S<<right;
}