#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
long long c[MAX] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int foo, bar;
		cin >> foo >> bar;
		c[foo] += bar;
	}
	for(int i = 0; i < MAX; i++) {
		if(k - c[i] <= 0) {
			cout << i << endl;
			return 0;
		}
		k -= c[i];
	}

}