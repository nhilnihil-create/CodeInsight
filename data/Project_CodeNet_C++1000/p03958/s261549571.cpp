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
	int K,T;
	cin >> K >> T;
	vector<int> A(T);
	rep(i,T) cin >> A[i];
	sort(A.begin(),A.end(),greater<int>());
	int acc = 0;
	for(int i=1; i<T; i++) acc+=A[i];
	int ans = max(0, A[0]-acc-1);
	cout << ans << endl;

  return 0;
}
