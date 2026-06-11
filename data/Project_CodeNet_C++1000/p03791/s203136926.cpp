#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>
#include <vector>
#include<string>
#include <limits.h>

using namespace std;


int main() {
	long long n, i, r, x[111111], ans = 1, mod = 1000000007;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> x[i];
	r = 1;
	for (i = 0; i < n; i++) {
		while (1) {
			if (r + 1 <= n && x[r + 1] >= 2 * (r - i)){
				r++;
              	if(x[r]==2*(r-i-1))
                  break;
            }
			else
				break;
		}
		ans = ans * (r - i) % mod;
	}
	cout << ans << endl;
}
