#include <bits/stdc++.h>
using namespace std;
int main(){
	long long i, o, t, j, l, s, z;
	cin >> i >> o >> t >> j >> l >> s >> z;
	long long ans = 2 * o;
	auto best = [](long long I, long long J, long long L){
		long long ans = 0;
		if(I > 0 && J > 0 && L > 0) ans = max(ans, 6 + ((I - 1) / 2) * 4 + ((J - 1) / 2) * 4 + ((L - 1) / 2) * 4);
		ans = max(ans, (I/2)*4 + (J/2)*4 + (L/2)*4);
		return ans;
	};
	ans += best(i, j, l);
	cout << ans / 2 << endl;
	return 0;
}
