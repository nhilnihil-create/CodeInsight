#include<bits/stdc++.h>
using namespace std;

int main () {
	int n; cin >> n;
	int a[100000];
	bool b[100000] = {false};
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int x=0;
	int c=0;
	while (a[x]!=2 && b[x]==false) {
		b[x] = true;
		x=a[x]-1;
		c++;
	}
	if (b[x]==true) cout << -1; else cout << c+1;
	return 0;
} 