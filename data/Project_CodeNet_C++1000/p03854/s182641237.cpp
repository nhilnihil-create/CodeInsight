#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  deque<char> dq;
  for (int i = 0; i < S.size(); i++) {
    dq.push_back(S.at(i));
  }
  bool b = 1;
  while (!dq.empty()) {
    if (dq.size()>= 5 && dq.at(0)=='d' && dq.at(1)=='r' && dq.at(2)=='e' && dq.at(3)=='a' && dq.at(4)=='m') {
      for (int i = 0; i < 5; i++) {
        dq.pop_front();
      }
      if (!dq.empty() && dq.at(0)=='e' && dq.at(1)=='r' && (dq.size()==2 || (dq.size()>2 && dq.at(2)!='a'))) {
        for (int i = 0; i < 2; i++) {
          dq.pop_front();
        }
      }
    }
    else if (dq.size()>=5 && dq.at(0)=='e' && dq.at(1)=='r' && dq.at(2)=='a' && dq.at(3)=='s' && dq.at(4)=='e') {
      for (int i = 0; i < 5; i++) {
        dq.pop_front();
      }
      if (!dq.empty() && dq.at(0)=='r') {
        dq.pop_front();
      }
    }
    else {
      b = 0;
      break;
    }
  }
  if (b == 0) {
    cout << "NO" << endl;
  }
  if (b == 1) {
    cout << "YES" << endl;
  }
}