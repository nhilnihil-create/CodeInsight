#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
const int inf = (1<<30);

int main() {
  int N, T; cin >> N >> T;
  vector<int> a(N);
  vector<int> cmax(N);
  int ans = 0;
  int profit = 0;
  for(int i = 0; i < N; ++i) {
    cin >> a[i];
    cmax[i] = a[i];
  }
  for(int i = N-1; i >= 0; --i) {
    if(i+1 < N) chmax(cmax[i], cmax[i+1]);
  }

  for(int i = 0; i < N; ++i) {
    if(chmax(profit, cmax[i] - a[i])) ans = 0;
    if(profit == cmax[i] - a[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
