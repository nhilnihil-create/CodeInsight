#include <bits/stdc++.h>
using namespace std;
#define int long long int
main(){
    int n;
    cin >> n;
    int a[n];
    int cnt=0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	if (cnt % (n*(n + 1) / 2)) {
		cout << "NO" << endl;
		return 0;
	}
	int k = cnt / (n*(n + 1) / 2);
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		int x = a[(i + 1) % n] - a[i];
		if (k < x) {
			cout << "NO" << endl;
			return 0;
		}
		if ((k - x) % n) {
			cout << "NO" << endl;
			return 0;
		}
		cnt2 += (k - x) / n;
	}
	if (cnt2 == k)cout << "YES" << endl;
	else cout << "NO" << endl;
    
}