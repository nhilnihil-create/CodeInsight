#include<bits/stdc++.h>
using namespace std;
  
int main() {
	long long pw[11]; pw[0] = 1;
	for (int i = 1; i <= 10; ++i) pw[i] = 1ll * pw[i - 1] * 10;
	int num = 0;
	for (int i = 1 ; i <= 10; ++i)   {
		cout << "? " << pw[i] << "\n";
		cout.flush();
		char c; cin >> c;
		if(c == 'N') {
			num = i;
			break;
		}
	}
	
	if(num == 0) {
		for(int i = 1; i <= 10; ++i) {
			cout << "? " << pw[i] - 1 << "\n";
			cout.flush();
			char c; cin >> c;
			if(c == 'Y') {
				cout << "! " << pw[i - 1] << "\n";
				cout.flush(); exit(0);
			}
		}
	}
	
	long long l = pw[num - 1], r = pw[num] - 1;
	while(l < r)   {
		long long mid = (l + r) >> 1;
		cout << "? " << mid * 10 << "\n";
		cout.flush();
		char c; cin >> c;
		if(c == 'Y') r = mid;
		else l = mid + 1;
	}
	cout << "! " << l << "\n";
	cout.flush();
}