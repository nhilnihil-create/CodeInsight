#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	
	cin >> n;
	vector<long long> a(n+3);

	int count = 0;
	int t = 0;

	long long x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int i = 0;
	while(1){
		if (a[i] < a[i+1]) {
			while (a[i] <= a[i + 1]) {
				i++;
				if (i >= n - 1)break;
			}
			count++;
			i++;
			if (i == n - 1) {
				count++;
				break;
			}

		}
		else if (a[i] > a[i + 1]) {
			while (a[i] >= a[i + 1]) {
				i++;
				if (i >= n - 1)break;
			}
			count++;
			i++;
			if (i == n - 1) {
				count++;
				break;
			}
		}
		else {
			i++;
			if (i >=n-1)break;
		}

	}

	cout << count << endl;
	return 0;
}