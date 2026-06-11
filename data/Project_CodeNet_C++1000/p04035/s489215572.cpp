#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, sum;
	cin >> n >> sum;
	long long a[n + 1];
	for(long long i = 1; i <= n; i++) {
        cin >> a[i];
	}
	bool f = false;
	long long pos = -1;
	for(long long i = 1; i < n; i++) {
        if(a[i] + a[i + 1] >= sum) {
            f = true;
            pos = i;
            break;
        }
	}
	if(!f) {
        cout << "Impossible" << endl;
	}
	else {
        cout << "Possible" << endl;
        for(long long i = 1; i < pos; i++) {
            cout << i << endl;
        }
        for(long long i = n - 1; i > pos; i--) {
            cout << i << endl;
        }
        cout << pos << endl;
	}
	return 0;
}
