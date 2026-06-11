#include <iostream>
#include <stack>

int main() {
  std::string S;
  std::cin >> S;
  
  std::stack<char> st;
  for (int i = 0; i < S.size(); i++) {
    if (!st.empty() && st.top() == 'S' && S[i] == 'T')
      st.pop();
    else
      st.push(S[i]);
  }
  
  std::cout << st.size() << '\n';
}