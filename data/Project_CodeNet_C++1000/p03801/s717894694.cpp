#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, a[100000], mx, t;
int p[100001];
ll res[100000], c;

int main() {
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> a[i];
		p[i] = a[i];
	}
	sort(p, p + N);
	p[N] = intmax;
	c = N;
	for (int i = 0; i != N; ++i) {
		if (mx < a[i]) {
			for (; p[t] <= a[i]; ++t) {
				res[i] += p[t] - mx;
				--c;
			}
			res[i] += (a[i] - mx)*c;
			mx = a[i];
		}
	}
	for (int i = 0; i != N; ++i)
		cout << res[i] << endl;
	return 0;
}