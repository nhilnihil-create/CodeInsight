#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

// ====================================================================

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    st.insert(v[i]);
  }
  sort(v.begin(), v.end());
  // cout << v << endl;

  int count = 0;
  for (int i = 0; i < n - 1; i++)
    if (v[i + 1] == v[i]) count++;

  if (count % 2 == 0) {
    cout << st.size() << endl;
  } else {
    cout << st.size() - 1 << endl;
  }
}
