#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int a[N];
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  sort(a,a+N,greater<int>());
  int sum=0;
  int ans=N;
  for (int i=0; i<N; i++) {
    if (sum+a[i]<K) {
      sum+=a[i];
    } else {
      ans=N-i-1;
    }
  }
  cout << ans << endl;
  return 0;
}
