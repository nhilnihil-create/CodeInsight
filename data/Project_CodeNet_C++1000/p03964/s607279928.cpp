#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N; cin >> N;
  vector<int> T(N),A(N);
  rep(i,N) cin >> T[i] >> A[i];
  
  ll ansT,ansA;
  ansT = ansA = 1;
  rep(i,N) {
    ll t = (ansT + T[i] - 1) / T[i];
    ll a = (ansA + A[i] - 1) / A[i];

    ansT = max(t,a) * T[i];
    ansA = max(t,a) * A[i];
  }

  cout << ansT + ansA << endl;

}