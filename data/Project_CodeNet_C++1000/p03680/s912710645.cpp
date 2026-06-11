#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int a[N+1];
	rep(i,N) cin >> a[i+1];
	int ans = 0;
	int now = 1;
	while (ans<N) {
		ans++;
		now = a[now];
		if (now == 2) {
			cout << ans << endl;
			return 0;
		}	
	}
	cout << -1 << endl;
	return 0;
}
