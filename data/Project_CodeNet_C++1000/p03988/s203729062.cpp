	#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int n;
  cin >> n;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  int lst = *st.rbegin();
  st.erase(--st.end());
  if (lst != *st.rbegin()) {
    cout << "Impossible\n";
    exit(0);
  }
  st.erase(--st.end());
  if (lst & 1) {
    for (int i = lst - 1; i >= (lst + 1) / 2; i--) {
      for (int j = 0; j < 2; j++) {
        if (st.find(i) == st.end()) {
          cout << "Impossible\n";
          exit(0);
        }
        st.erase(st.find(i));
      }
    }
    if (st.empty() || *st.begin() > (lst + 1) / 2) {
      cout << "Possible\n";
    }
    else {
      cout << "Impossible\n";
    }
  }
  else {
    for (int i = lst - 1; i > lst / 2; i--) {
      for (int j = 0; j < 2; j++) {
        if (st.find(i) == st.end()) {
          cout << "Impossible\n";
          exit(0);
        }
        st.erase(st.find(i));
      } 
    }
    if (st.find(lst / 2) == st.end()) {
      cout << "Impossible\n";
      exit(0);
    }
    st.erase(st.find(lst / 2));
    if (st.empty() || *st.begin() > lst / 2) {
      cout << "Possible\n";
    }
    else {
      cout << "Impossible\n";
    } 
  }
}