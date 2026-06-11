#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, M, a[100000], c;
ll MIN, t;
vector<int>v[100000];

int main() {
	cin >> N >> M;
	for (int i = 0; i != N; ++i) {
		cin >> a[i];
		--a[i];
		v[a[i]].push_back(i);
	}
	for (int i = 1; i != N; ++i) {
		if (a[i - 1] != 0 && a[i] && a[i] < a[i - 1]) {
			++c;
		}
		t += min(a[i] + 1, (M + a[i] - a[i - 1]) % M);
	}
	MIN = t;
	//cout << t << sp << c << endl;
	for (int i = 1; i != M; ++i) {
		t -= c;
		for (int j = 0; j != v[i - 1].size(); ++j) {
			if (v[i - 1][j] != N - 1)
				++c;
			if (v[i - 1][j]) {
				t += (M + a[v[i - 1][j]] - a[v[i - 1][j] - 1]) % M - 1;
			}
		}
		for (int j = 0; j != v[i].size(); ++j) {
			if (v[i][j]) {
				--c;
			}
		}
		//cout << t << sp << c << endl;
		MIN = min(MIN, t);
	}
	cout << MIN << endl;
	return 0;
}