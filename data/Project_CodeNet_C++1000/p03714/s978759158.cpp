// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int aa[N * 3];
long long pp[N + 1], qq[N + 1];
int pq[N * 2], ip[N + 1], cnt;

bool lt(int i, int j) {
	return aa[i] < aa[j];
}

int p2(int p) {
	return (p *= 2) > cnt ? 0 : p < cnt && lt(ip[p + 1], ip[p]) ? p + 1 : p;
}

void pq_dn(int i) {
	int j, p, q;
	for (p = pq[i]; (q = p2(p)) > 0 && lt(j = ip[q], i); p = q)
		ip[pq[j] = p] = j;
	ip[pq[i] = p] = i;
}

void pq_add_last(int i) {
	ip[pq[i] = ++cnt] = i;
}

void solve(long long *pp, int n) {
	cnt = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		pq_add_last(i);
		sum += aa[i];
	}
	for (int p = cnt / 2; p; p--)
		pq_dn(ip[p]);
	for (int i = n; i < n * 2; i++) {
		pp[i - n] = sum;
		int d = aa[i] - aa[ip[1]];
		if (d > 0) {
			sum += d;
			pq[i] = 1, pq_dn(i);
		}
	}
	pp[n] = sum;
}

int main() {
	int n; cin >> n;
	int n3 = n * 3;
	for (int i = 0; i < n3; i++)
		cin >> aa[i];
	solve(pp, n);
	for (int i = 0; i < n3; i++)
		aa[i] = -aa[i];
	for (int i = 0, j = n3 - 1; i < j; i++, j--)
		swap(aa[i], aa[j]);
	solve(qq, n);
	long long ans = -0x3f3f3f3f3f3f3f3fLL;
	for (int i = 0; i <= n; i++)
		ans = max(ans, pp[i] + qq[n - i]);
	cout << ans << '\n';
	return 0;
}
