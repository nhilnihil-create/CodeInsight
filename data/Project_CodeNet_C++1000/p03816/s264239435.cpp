#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int main() {
	int n, arr[MAX];
	cin >> n;
	
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	int k = 1;
	
	for (int i=0; i<n-1; ++i) {
		if (arr[i + 1] > arr[i]) k++;
	}
	
	if (k%2) cout << k;
	else cout << k-1;
	return 0;
}


