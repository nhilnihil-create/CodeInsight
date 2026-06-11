#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, x;
  cin>>N>>x;
  long long a[N];
  for (int i=0; i<N; i++) cin>>a[i];

  long long min_a[N];
  for (int i=0; i<N; i++) min_a[i] = 1e13;

  long long ans = 1e13;

  for (int limit=0; limit<N; limit++) {
    long long t = 0;
    for (int i=0; i<N; i++) {
      int j = (i - limit + N) % N;
      if (a[j] < min_a[i]) {
        min_a[i] = min(a[j], min_a[i]);
      }
      t += min_a[i];
    }
    ans = min(t + limit * x, ans);
  }
  cout<<ans<<endl;
}