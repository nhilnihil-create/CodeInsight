#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> st;
  int a;
  while (cin >> a) {
    auto itr = st.find(a);
    if (itr == st.end())
      st.insert(a);
    else
      st.erase(itr);
  }
  cout << static_cast<int>(st.size()) << endl;
}
