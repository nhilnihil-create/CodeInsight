#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 1e3 + 5;

ll a, b, cura = 1, curb = 1, cnt;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a >> b;
		cnt = max((cura + a - 1) / a, (curb + b - 1) / b);
		cura = cnt * a;
		curb = cnt * b;
	}
	cout << cura + curb << endl;
	return 0;
}

