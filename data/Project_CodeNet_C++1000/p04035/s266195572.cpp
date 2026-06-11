#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, L, pos = 0, a[N];

int main() {
	cin >> n >> L;
	for(int i = 1;i <= n; ++i) cin >> a[i];
	for(int i = 1;i <  n; ++i) 
		if(a[i] + a[i + 1] >= L) 
			pos = i;
	if(pos) {
		puts("Possible");
		for(int i = 1;i < pos; ++i)
			cout << i << endl;
		for(int i = n - 1;i > pos; --i)
			cout << i << endl;
		cout << pos << endl;
	} else {
		puts("Impossible");
	}
	return 0;
}