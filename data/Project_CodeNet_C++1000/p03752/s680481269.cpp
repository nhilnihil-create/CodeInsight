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
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	ll mini = 1e18;
	rep(i, (1<<N)) {
		ll res = 0;
		if(__builtin_popcount(i) < K) continue;
		if(!(i & 1)) continue;
		//cout << bitset<5>(i) << endl;
		ll previousHeight = 0;
		ll currentHeight = -1;
		rep(j,N) {
			if(!((i >> j) & 1)) {
				continue;
			}
			for(int k=j+1; k<N; k++) {
				if(!((i >> k) & 1)) {
					chmax(currentHeight, A[k]);
				}
				if((i >> k) & 1) break;
			}
			//cout << j << " ";
			//cout << previousHeight << " " << currentHeight << " " << A[j] << endl;
			ll shouldBe = max(previousHeight, currentHeight);
			if (shouldBe >= A[j]) res += shouldBe + 1 - A[j];
			previousHeight = max(shouldBe+1, A[j]);
			currentHeight = 0;
			/*	
				if(currentHeight < A[j]) {
					currentHeight = A[j];
				}
				else {
					res += currentHeight + 1 - A[j];
					currentHeight++;
				}
			}
			*/
		}
		//cout << res << endl;
		chmin(mini, res);
	}
	cout << mini << endl;

  return 0;
}
