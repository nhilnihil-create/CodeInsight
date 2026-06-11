#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	vector<long long> a;
	cin >> n;
	long long A;
	
	for (int i = 0; i < n; i++) {
		cin >> A;
		a.push_back(A);
	}


	long long ans1 = 0;
	long long count = 0;
	
	for (int i = 0; i < n ; i++) {
		ans1 += a[i];
		if (i % 2 == 0) {
			if (ans1 >= 0) {
				
				count += ans1 + 1;
				ans1 = -1;
			}
		}
		else {
			if (ans1 <= 0) {
				count += 1 - ans1;
				ans1 = 1;
			}
		}
	}
	

	long long count2 = 0;
	ans1 = 0;
	for (int i = 0; i < n ; i++) {
		ans1 += a[i];
		if (i % 2 != 0) {
			if (ans1 >= 0) {

				count2 += ans1 + 1;
				ans1 = -1;
			}
		}
		else {
			if (ans1 <= 0) {
				count2 += 1 - ans1;
				ans1 = 1;
			}
		}
	}

	cout << min(count, count2) << endl;

	return 0;
}