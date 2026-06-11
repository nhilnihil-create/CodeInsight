#include<bits/stdc++.h>

using namespace std;

int main() {
	int k, t, m;
	cin >> k >> t;
	cin >> m;
	t--;
	while(t--){
		int num;
		cin >> num;
		m = max(m, num);
	}
	cout << max(0, m - (k + 1 - m));
	return 0;
}
