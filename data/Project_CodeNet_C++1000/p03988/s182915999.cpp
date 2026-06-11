#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  multiset<int> st;
  int diam = 0;
  REP(i, n) {
    int a;
    cin >> a;
    st.insert(a);
    diam = max(diam, a);
  }
  if (diam % 2 == 0) {
    for (int i = diam; i > diam / 2; --i) {
      if (st.find(i) != st.end()) {
        st.erase(st.find(i));
      } else {
        cout << "Impossible" << endl;
        return 0;
      }
    }
    for (int i = diam / 2; i <= diam; ++i) {
      if (st.find(i) != st.end()) {
        st.erase(st.find(i));
      } else {
        cout << "Impossible" << endl;
        return 0;
      }
    }
    if (st.empty()) {
      cout << "Possible" << endl;
      return 0;
    } else if (*st.begin() < diam / 2 + 1) {
      cout << "Impossible" << endl;
      return 0;
    }
    cout << "Possible" << endl;
  } else {
    for (int i = diam; i >= (diam + 1) / 2; --i) {
      if (st.find(i) != st.end()) {
        st.erase(st.find(i));
      } else {
        cout << "Impossible" << endl;
        return 0;
      }
    }
    for (int i = (diam + 1) / 2; i <= diam; ++i) {
      if (st.find(i) != st.end()) {
        st.erase(st.find(i));
      } else {
        cout << "Impossible" << endl;
        return 0;
      }
    }
    if (st.empty()) {
      cout << "Possible" << endl;
      return 0;
    } else if (*st.begin() < (diam + 1) / 2 + 1) {
      cout << "Impossible" << endl;
      return 0;
    }
    cout << "Possible" << endl;
  }
  return 0;
}