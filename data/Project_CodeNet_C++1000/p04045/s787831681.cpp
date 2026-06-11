#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, k; cin >> n >> k;
	vector<char> d(k);
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	int ans = 0;
	for (int i = n; i <= 100000 ; i++) {
		string tmp = to_string(i);
		bool can = true;
		for (int j = 0; j < tmp.size(); j++) {
			for (int x = 0; x < k; x++) {
				if (tmp[j] == d[x]) {
					can = false;
				}
			}			
		}
		if (can) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}