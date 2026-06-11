#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  set<char> st;
  for(int i = 0; i < S.size(); i++) {
    st.insert(S[i]);
  }

  if(st.size() == S.size()) cout << "yes";
  else cout << "no";
  return 0;
}