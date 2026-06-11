#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  stack<char> st;

  for(int i=0; i<s.size(); i++){
    if(s[i] == 'S'){
      st.push(s[i]);
    }else{
      if(st.empty() || st.top() == 'T'){
        st.push(s[i]);
      }else{
        st.pop();
      }
    }
  }
  cout << st.size() << endl;
  return 0;
}