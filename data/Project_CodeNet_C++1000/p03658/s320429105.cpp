#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
const int MOD = 1e9+7;
 
int main() {
	int N,K;
  	cin >> N >> K;
  	vi l(N);
  	rep(i,N) cin >> l[i];
	sort(l);
  	riverse(l);
  	int ans = 0;
  	rep(i,K)ans += l[i];
  	cout << ans << endl;
}