#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> b(N+1, 1);
	b[0] = 0;
	vector<int> r(N+1);
	r[1] = 1;
	rep(i,M) {
		int x, y;
		cin >> x >> y;
		if (r[x] == 1 ) r[y] = 1;
		if (r[x] == 1 && b[x] == 1) r[x] = 0;
		b[x]--; b[y]++;
	}

	int ans = 0;
	rep(i,N) ans += r[i+1];
	cout << ans << endl;
	return 0;
}
