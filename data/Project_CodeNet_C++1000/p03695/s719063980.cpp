#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int rate[9];
	rep(i,9) rate[i] = 0;
	rep(i,N) {
		int a;
		cin >> a;
		a /= 400;
		if (a >= 8) rate[8]++;
		else  rate[a] = 1;
	}

	int ans_min = 0, ans_max;
	rep(i,8) ans_min += rate[i];
	ans_max = ans_min + rate[8];

	if (ans_min == 0) {
		ans_min = 1;
		ans_max = rate[8]--;
	}
	cout << ans_min << " " << ans_max << endl;

	return 0;
}
