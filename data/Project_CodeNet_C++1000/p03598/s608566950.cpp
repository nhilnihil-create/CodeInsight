#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	vector<int> X;
	for(int i=0; i<N; i++){
		int x; cin >> x;
		X.push_back(x);
	}

	LL ans = 0;
	for(int i=0; i<N; i++){
		LL d = (LL)min(abs(X[i]), abs(X[i]-K));
		ans += (2*d);
	}
	printf("%lld\n", ans);
	return 0;
}