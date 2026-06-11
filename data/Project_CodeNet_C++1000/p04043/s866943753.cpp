#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int a, b, c; cin >> a >> b >> c;
	vector<int> num(8, 0);
	num[a]++;
	num[b]++;
	num[c]++;
	if (num[5] == 2 && num[7] == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}