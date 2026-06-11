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
	for (int i = 1; i <= N; i++) {
		if (a[a[i]] == i) ans++;	
	}
	ans /= 2;
	cout << ans << endl;
	return 0;
}
