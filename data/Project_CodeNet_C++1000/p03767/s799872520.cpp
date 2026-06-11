# include <iostream>
# include <algorithm>

using namespace std;

int main() {
  int N, a[300000];
  cin >> N;
  
  for (int i = 0; i < 3 * N; i++) cin >> a[i];
  sort(a, a + 3 * N);
  
  // int型だと桁あふれ？する
  long ans = 0;
  // 最大値2つと最小値1つの組み合わせのとき、最大となるはず
  for (int i = N; i < 3 * N; i+=2) ans += a[i];
  
  cout << ans << endl;
  
  return 0;
}