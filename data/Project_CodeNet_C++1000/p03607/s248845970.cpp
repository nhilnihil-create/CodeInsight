#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int n;
	cin >> n;
	map<int,int> m;
	for (int i = 0; i < n; ++i) {
		int y;
		cin >> y;
		m[y]++;
	}
	int cnt = 0;
	for (auto x : m) {
		if (x.second % 2 == 1) {
			cnt++;
		}
	}
	cout << cnt;
}


