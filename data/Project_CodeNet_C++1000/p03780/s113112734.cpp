#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int a[5001];
int main(int argc, const char * argv[]) {
  int n, k;
  cin >> n >> k;
  

  int ans = n;
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  sort(a, a + n);
  
  int sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (sum + a[i] < k) {
      sum += a[i];
    } else {
      ans = min(ans, i);
    }
  }
  cout << ans << endl;
  return 0;
}
