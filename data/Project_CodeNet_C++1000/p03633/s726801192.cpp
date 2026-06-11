#include "bits/stdc++.h"
using namespace std;
typedef pair<long long, long long> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
long long gcd(long long A, long long B) {
  	if (B == 0) return A;
  	else return gcd(B, A % B);
}
long long lcm(long long A, long long B) {
  	return A / gcd(A, B) * B;
}
int main() {
	long long N; cin >> N;
  	vector<long long>A(N);
  	for (long long i = 0; i < N; i++) cin >> A.at(i);
  	long long ans = 1;
  	sort(A.begin(), A.end());
  	for (long long i = 0; i < N; i++) {
      	ans = lcm(ans, A.at(i));
    }
  	cout << ans << endl;
}