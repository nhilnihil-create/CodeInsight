#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  for (int i=0; i<N; i++) cin >> A[i] >> B[i];
  ll ans = 0LL;
  for (int i=N-1; i>=0; i--) {
    if (i!=0&&A[i]%B[i]!=0) {
      ans += abs(A[i]-B[i]*(A[i]/B[i]+1));
      A[i-1] += ans;
    }
    else if (i==0&&A[i]%B[i]!=0) ans += abs(A[i]-B[i]*(A[i]/B[i]+1));
    else if (i!=0&&A[i]%B[i]==0) A[i-1] += ans;
  }
  cout << ans << endl;
}