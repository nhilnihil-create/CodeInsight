#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<30;
const int mod = 1e9+7;


int main() {
  int N; cin >> N;
  vector<int> A(N);
  set<int> st;
  for(int i = 0; i < N; i++) cin >> A[i], st.insert(A[i]);
  if(st.size() % 2 == 1) {
    cout << st.size() << endl;
  } else {
    cout << st.size() - 1 << endl;
  }

  return 0;
}

