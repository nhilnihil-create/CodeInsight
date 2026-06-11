#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <bitset>

#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define debugV(vec) rep(i,vec.size()) cout << vec[i] << " "; cout << endl;
typedef long long int llint;

using namespace std;

const llint inf = pow(10, 12);

int main(void) {
	int n;
	cin >> n;

	vector<int> a(n);
	rep(i,n) cin >> a[i];

	sort(a.begin(),a.end());

	int even = 0, size = 1, group = 1;
	rep(i,n-1) {
		if (a[i] == a[i+1]) {
			size++;
		}
		else {
			group++;
			if (size % 2 == 0) even++;
			size = 1;
		}
	}
	if (size % 2 == 0) even++;
	if (even % 2 == 0) cout << group << endl;
	else cout << group - 1 << endl;
}

