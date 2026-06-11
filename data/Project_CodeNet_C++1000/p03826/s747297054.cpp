#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;

int n;

int main() {

	FAST;

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(a * b, c * d) << '\n';
	return 0;
}