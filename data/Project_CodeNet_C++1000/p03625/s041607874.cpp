#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int n;
	cin >> n;
	ll A[n];
	rep(i, n) cin >> A[i];
	sort(A, A+n, greater<ll>());

	int cnt = 1;
	ll first = 0;
	ll ans = 0;
	for (int i=0; i<n-1; i++) {
		if (A[i]==A[i+1]) {
			cnt++;
			if (cnt== 4) {
				ans = A[i]*A[i];
				cout << ans << endl;
				return 0;
			}
			else if (cnt==2) {
				if (first==0) first = A[i];
				else {
					ans = first * A[i];
					cout << ans << endl;
					return 0;
				}
			}
		}
		else cnt = 1;
	}
	cout << ans << endl;
}