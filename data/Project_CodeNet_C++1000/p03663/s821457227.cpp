#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
#define int long long
 
signed main() {
	int dig = -1;//10^p
	for (int i = 0; i < 10; i++) {
		int a = pow(10, i);
		cout << "? " << a << endl;
		char c;
		cin >> c;
		if (c == 'N') {
			dig = i-1;
			break;
		}
	}
	
	if (dig == -1) {
		for (int i = 0; i < 10; i++) {
			int a = pow(10, i) + 1;
			cout << "? " << a << endl;
			char c;
			cin >> c;
			if (c == 'Y') {
				int ans = pow(10, i);
				cout <<"! "<<ans<< endl;
				return 0;
			}
		}
	}
	int lb=pow(10,dig+1), ub=pow(10,dig+2);
 
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		cout << "? " << mid << endl;
		char c;
		cin >> c;
		if (c == 'Y') {
			ub = mid;
		}
		else lb = mid;
	}
	cout << "! " << ub/10 << endl;
}