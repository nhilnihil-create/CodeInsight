#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int A,B,C,D;cin>>A>>B>>C>>D;
  int bucket[101] = {0};

  for(int i = A; i < B+1; i++) {
    bucket[i] ++;
  }

  for(int i = C; i < D+1; i++) {
    bucket[i] ++;
  }

  int ans = 0;
  for (int i = 0; i < 101; i++) {
    if (bucket[i] == 2) {
      ans ++;
    }
  }

  if (ans > 0) cout << ans-1 << endl;
  else cout << ans << endl;
  return 0;
}