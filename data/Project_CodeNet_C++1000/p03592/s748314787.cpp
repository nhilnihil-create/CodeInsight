#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M,K;
	cin >> N >> M >> K;

	bool ans = false;

	rep(i,N+1){
		rep(j,M+1){
			int kazu = i * M + j * N - 2 * i * j;
			if(kazu == K) ans = true; 
		}
	}

	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}