#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, l, i, j, k;
	cin >> n >> l;
	vector<long long> a(n);
	bool found = false;
	for (i = 0; i < n; i++) cin >> a[i]; 
	for (i = 1; i < n; i++) {
		if (a[i] + a[i - 1] >= l) {
			found = true;
			cout << "Possible\n";

			for (j = 1; j < i; j++) cout << j << "\n";
			for (j = n - 1; j >= i + 1; j--) cout << j << "\n";
			cout << i << "\n";

			break;
		}
	}
	if (!found) cout << "Impossible\n";


	return 0;
}
