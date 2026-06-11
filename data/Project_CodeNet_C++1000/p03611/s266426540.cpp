#include<bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	long long a[100000];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	long long pos[100000];
	for (int i=0; i<100000; i++) pos[i]=1000000;
	for (int i=0; i<n; i++) {
		pos[a[i]] = i;
		while (a[i] == a[i+1]) i++;
	}
	long long ans = 1;
	for (int i=0; i<n; i++) {
		ans= max(ans, max(i - pos[a[i]-1] + 1, i - pos[a[i]-2] + 1));
	}
	cout << ans;
	return 0;
}