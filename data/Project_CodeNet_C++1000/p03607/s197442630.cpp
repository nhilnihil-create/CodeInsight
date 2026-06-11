#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(int)(n);i++)

long long gcd(long long p, long long q) {
	if (p < q) swap(p, q);
	if (p % q == 0) return q;
	else return gcd(p / q, p % q);
}
int keta(long long p, int q) {
	if (p / 10 == 0) return q + 1;
	else return keta(p / 10, q + 1);
}
long long kaijo(int p, int q) {
	if (p == 1) return q;
	else return kaijo(p - 1, p * q);
}

int main() {
	long N, ans;
	ans = 0;
	cin >> N;
	vector<long> vec(N);
	rep(i, N) cin >> vec[i];
	sort(vec.begin(), vec.end());
	pair<long, long> count;
	rep(i, N) {
		if (count.first != vec[i]) {
			if (count.second != (count.second / 2) * 2) ans++;
			count = make_pair(vec[i], 1);
		}
		else count.second++;
	}
	if (count.second != (count.second / 2) * 2) ans++;
	cout << ans << endl;
}