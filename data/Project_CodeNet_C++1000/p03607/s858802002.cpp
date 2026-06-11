#include<bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	int l=0;
	map<int, int> m;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		if (m[x]==0) {	
			m[x] = 1;
			l++;	
		} else {
			m[x]=0;
			l--;
		}
	}
	cout << l;
	return 0;
}