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
  long long N, A, B; cin >> N >> A >> B;
  vector<long long> X(N);
  for(int i = 0; i < N; i++) {
    cin >> X[i];
  }
  long long ans = 0;
  for(int i = 1; i < N; i++) {
    ans += min((X[i] - X[i-1])*A, B);
  }
  cout << ans << endl;

  return 0;
}

