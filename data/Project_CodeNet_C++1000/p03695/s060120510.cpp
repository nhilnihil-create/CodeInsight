#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {

  int N; cin >> N;
  set<int> st;
  int count = 0;
  rep(i, N) {
    int a; cin >> a;
    if (a >= 3200) {
      count++;
    } else {
      st.insert(a / 400);
    }
  }

  if (st.size() == 0) {
    cout << "1 ";
  } else {
    cout << st.size() << " ";
  }
  cout << st.size() + count << "\n";
  
  return 0;
}