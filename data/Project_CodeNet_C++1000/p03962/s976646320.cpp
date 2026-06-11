#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  set<int> st;
  st.insert(a);
  st.insert(b);
  st.insert(c);
  cout << st.size() << "\n";
}
