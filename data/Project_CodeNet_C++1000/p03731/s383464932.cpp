#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, T;
  cin >> N >> T;
  vector<long long> t(N);
  for(long long i = 0; i < N; i++) {
    cin >> t[i];
  }
  long long ans = t[0];
  for(long long i = 1; i < N; i++) {
    if(t[i - 1] + T < t[i]) ans += T;
    else ans += (t[i] - t[i - 1]);
  }
  ans += T;

  cout << ans << endl;


  return 0;
}
