#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, C, K;
	cin >> N >> C >> K;
	int T[N];
	rep(i,N) cin >> T[i];
	sort(T,T+N);

	int ans = 0;
	int n = 1;
	int t = T[0];
	for (int i = 1; i < N; i++) {
		if (T[i]>t+K || n==C) {
			ans++;
			n = 0;
			t = T[i];	
		}
		n++;
	}
	if (n != 0) ans++;
	cout << ans << endl;
	return 0;
}
