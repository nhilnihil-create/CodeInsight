#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)




int main() {
	int N, K,ave,tmp;
	cin >> N >> K;
	ave = K / 2;
	int ans = 0;
	rep(i, N) {
		cin >> tmp;
		if (tmp<=ave)
		{
			ans += 2 * tmp;
		}
		else if (tmp>ave)
		{
			ans += (K - tmp) * 2;
		}
	}
	cout << ans << endl;
}
