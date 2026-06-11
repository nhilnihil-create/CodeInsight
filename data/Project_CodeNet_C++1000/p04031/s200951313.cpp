#include<bits/stdc++.h>
using namespace std;
int main () {
	int n; cin >> n;
	vector<int> a;
	int tbc = 0;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		a.push_back(x);
		tbc += x;
	}
	int k[3];
	k[0] = tbc/n-1;
	k[1] = tbc/n;
	k[2] = tbc/n+1;
	int mi = 1e9;
	for (int j=0; j<3; j++) {
		int s = 0;
		for (int i=0; i<n; i++) {
			s += (a[i]-k[j])*(a[i]-k[j]);
		}
		mi = min(mi, s);
	}
	cout << mi;
	return 0;
}