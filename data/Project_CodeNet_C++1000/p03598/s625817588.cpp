#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N,K;
	cin >> N >> K;
	vector<int> X(N);
	rep(i,N) cin >> X[i];
	int ans = 0;
	rep(i,N) {
		ans += min(X[i]*2, abs(K - X[i])*2);
	}
	cout << ans << endl;

  return 0;
}
