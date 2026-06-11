/**
 * 	ЫЫ
**/
#include <bits/stdc++.h>
    
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
    
using namespace std;

const int N = 1e5 + 5;

int n, a[N], ans;

main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) {
			if (i == n) {
				ans++;
				break;
			}
			swap(a[i], a[i + 1]);
			ans++;
		}
	}
	cout << ans << endl;
}
