#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	const int p = 100001;
	vector<int> num(p, 0);
	for (int i = 0; i < n; i++) {
		int a;  cin >> a;
		num[a]++;
	}
	int existCnt = 0;
	int num_even_Cnt = 0;
	for (int i = 0; i < p; i++) {
		if (0 < num[i]) existCnt++;
		if (0 < num[i] && num[i] % 2 == 0) {
			num_even_Cnt++;
		}
	}
	if (num_even_Cnt % 2 == 0) {
	}
	else if (num_even_Cnt % 2 == 1) {
		existCnt--;
	}
	cout << existCnt << endl;
	return 0;
}