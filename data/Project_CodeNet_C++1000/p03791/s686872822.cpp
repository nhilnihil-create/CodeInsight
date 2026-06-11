#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>(b);i--)
#define pb push_back

typedef long long ll;
using namespace std;
int MOD = 1000000007;
int N, x, min_rank = 0;
ll ans = 1;

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  FOR(i, 0, N - 1){
    cin >> x;
    if(min_rank < (i * 2 - x + 2) / 2){
      ans = ans * (i + 1 - min_rank) % MOD;
      min_rank++;
    }
  }
  FOR(i, min_rank, N){
    ans = ans * (N - i) % MOD;
  }
  cout << ans << endl;
}
