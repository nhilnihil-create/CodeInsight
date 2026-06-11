#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  vector <int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  long long ans = 200*200*100;
  for (int i = -100; i <= 100; i++) {
    long long wk_ans = 0;
    for (int j = 0; j < N; j++) {
      wk_ans += ((a[j]-i)*(a[j]-i));
    }
    ans = min(ans, wk_ans);
  }
  cout << ans << endl;
  return 0;
}
