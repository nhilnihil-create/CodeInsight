#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1e5 + 10;

int ar[MAXn], n, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> ar[i];
		ar[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (ar[i] == i) {
			swap(ar[i], ar[i+1]);
			ans++;
		}
	
	}
	cout << ans;


}
