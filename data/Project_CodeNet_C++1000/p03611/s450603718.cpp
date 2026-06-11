#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;
const int MAXN = 100010;

int main() {
	int N;
	cin >> N;

	vector <int> b(MAXN);
	for (int ii = 0; ii < N; ++ii){
		int a;
		cin >> a;
		b[a] += 1;
		b[a+1] += 1;
		if (a > 0) b[a-1] += 1;
	}

	sort(b.rbegin(), b.rend());
	cout << b[0] << "\n";

	return 0;
}
