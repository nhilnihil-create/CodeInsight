#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
long long arr[MAXN];
long long temp[MAXN];

int n, k;

int main () {
	cin >> n >> k;
	// input and temp
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		if (i > 0) {
			if (arr[i] > 0)
				temp[i] = temp[i - 1] + arr[i];
			else
				temp[i] = temp[i - 1];
			arr[i] = arr[i - 1] + arr[i];	
		}
		else {
			if (arr[i] > 0)
				temp[i] = arr[i];
			else 
				temp [i] = 0;
		}
	}
	
	long long ans = 0;
	for (int i = 0; i <= n - k; i ++) {
		long long tmpans = 0;
		long long jam;
		if (i > 0)
			jam = arr[i + k - 1] - arr[i - 1];
		else
			jam = arr[i + k - 1];
		if (jam > 0)
			tmpans = jam;
		if (i >= 1)
			tmpans += temp[i - 1];
		tmpans += (temp[n - 1] - temp[i + k - 1]);
		ans = tmpans > ans ? tmpans : ans;
	}
	cout << ans << endl;
	return 0;
}
