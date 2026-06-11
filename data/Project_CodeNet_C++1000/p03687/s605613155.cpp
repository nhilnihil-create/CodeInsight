#include <bits/stdc++.h>
using namespace std;
int INF = 10000;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  set<char> st;
  for (int i = 0; i < N; i++){
    st.insert(s[i]);
  }
  int ans = INF;
  for (char c : st){
    vector<string> A(1);
    for (int i = 0; i < N; i++){
      if (s[i] == c){
        A.push_back("");
      } else {
        A.back().push_back(s[i]);
      }
    }
    int tmp = 0;
    for (int i = 0; i < A.size(); i++){
      int tmp2 = A[i].size();
      tmp = max(tmp, tmp2);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}