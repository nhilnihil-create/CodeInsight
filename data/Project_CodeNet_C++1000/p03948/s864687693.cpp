#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N, T;
	cin >> N >> T;
	int l = INF, s = 0;
	vector< pair<int, int> > apple;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a - l >= s) {
			if (a - l > s)apple.clear();
			s = a - l;
			apple.push_back({ l,a });
		}
		l = min(a, l);
	}
	cout << apple.size() << endl;
	return 0;
}