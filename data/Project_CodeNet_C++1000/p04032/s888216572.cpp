#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 111;

int a[N];

int sq(int x) {
	return x * x;
}

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	int l = -1, r = -1;
	for(int i = 0; i < str.size() - 1; ++i) {
		if(str[i] == str[i + 1]) {
			l = i + 1;
			r = i + 2;
		}
	}

	for(int i = 0; i + 2 < str.size(); i++) {
		if(str[i] == str[i + 2]) {
			l = i + 1;
			r = i + 3;
		}
	}

	cout << l << " " << r << endl;
}