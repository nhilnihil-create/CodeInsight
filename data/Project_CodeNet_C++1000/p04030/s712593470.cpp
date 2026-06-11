#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  string s;
  cin >> s;
  

  stack<char> st;

  for (int i = 0; i < s.size(); i++){
    if (s[i] == 'B'){
      if (!st.empty())
        st.pop();
    }
    else 
      st.push(s[i]);
  }

  string t = "";

  while (!st.empty()){
    t += st.top();
    st.pop();
  }
  reverse(t.begin(), t.end());

  for (auto c : t)
    cout << c;
  cout << endl;

  return 0;
}
