#include <bits/stdc++.h>
using namespace std;
int main(){
  string X;
  cin >> X;
  int N = X.size();
  stack<char> st;
  for (int i = 0; i < N; i++){
    if (X[i] == 'S'){
      st.push(X[i]);
    } else {
      if (!st.empty() && st.top() == 'S'){
        st.pop();
      } else {
        st.push(X[i]);
      }
    }
  }
  cout << st.size() << endl;
}