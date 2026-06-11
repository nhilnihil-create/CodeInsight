#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);
static const ll mod = 1;

ll calc_comb(int n, int r) {
  ll num = 1;
  for (int i = 1; i <= r; i++) {
    num = num * (n - i + 1) / i;
  }
  return num;
}


int main() {
  int N, A, B; cin >> N >> A >> B;
  vector<ll> v(N);
  rep(i, N) cin >> v[i];
  sort(all(v));
  reverse(all(v));

  ll sum = v[0];
  int last_idx = 0;
  for (int i = 1; i < A; i++) {
    sum += v[i];
    if (v[i] != v[i-1]) last_idx = i;
  }

  int first_idx = A - 1;
  for (int i = A; i < N; i++) {
    if (v[i] != v[i-1]) {
      break;
    }
    first_idx = i;
  }

  int same_cnt = first_idx - last_idx + 1;
  ll ans_comb = 0LL;
  if (last_idx == 0) {
    for (int i = A; i <= min(B, first_idx+1); i++) {
      ans_comb += calc_comb(first_idx+1, i);
    }
  } else {
    ans_comb = calc_comb(same_cnt, A-last_idx);
  }


  double ans_sum = (double)sum / A;
  printf("%.10f\n",ans_sum);
  cout << ans_comb << endl;
  
  return 0;
}
