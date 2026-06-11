# include <iostream>
# include <algorithm>

using namespace std;

int main() {
  int N, K, L[60];
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> L[i];
  
  sort(L, L + N);
  reverse(L, L + N);
  
  int ans = 0;
  for (int i = 0; i < K; i++) ans += L[i];
  cout << ans << endl;
  
  return 0;
}