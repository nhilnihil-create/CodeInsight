#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  ll N; cin >> N;
  ll A[N]; rep(i,N) cin >> A[i];
  ll sum = 0; rep(i,N) sum += A[i];
  if (sum%(N*(N+1)/2)!=0) { cout << "NO" << endl; return 0; }
  ll count = sum / (N*(N+1)/2);
  ll num = 0;
  rep(i,N) {
    ll diff = A[i] - A[(i+1)%N];
    if (diff+count<0||(diff+count)%N!=0) { 
      cout << "NO" << endl;
      return 0;
    }
    num += (diff+count)/N;
  }
  string result = (num==count) ? "YES" : "NO";
  cout << result << endl;
  return 0;
}