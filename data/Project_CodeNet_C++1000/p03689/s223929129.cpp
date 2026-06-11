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

	long long n, m, nn, mm, i, j, k, p = 1000;
	cin >> n >> m >> nn >> mm;
	if ((n % nn == 0) && (m % mm == 0)) cout << "No\n";
	else {
		cout << "Yes\n";
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if ((i % nn == nn - 1) && (j % mm == mm - 1)) cout << -(nn * mm * p - p + 1) << " ";
				else cout << p << " ";
			}
			cout << "\n";
		}
	}


	return 0;
}

