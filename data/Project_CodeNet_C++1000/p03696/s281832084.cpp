#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  
  deque<char> dq;
  for (int i = 0; i < N; i++) {
    dq.push_back(S[i]);
  } 
  
  
  vector<char> left;
  
  
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') left.push_back('(');
    
    if (S[i] == ')') {
      if (left.size()) {
        left.pop_back();
      } else {
        dq.push_front('(');
      }
    }
  }
  
  for (int i = 0; i < left.size(); i++) {
    dq.push_back(')');
  }

  for (int i = 0; i < dq.size(); i++) {
    cout << dq[i];
  }
    
  
  
}