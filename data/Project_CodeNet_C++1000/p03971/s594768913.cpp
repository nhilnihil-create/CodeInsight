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
#include <numeric>
#include <math.h> 

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, i, j, k, ct = 0, cbb = 0;
	string s;
	cin >> n >> a >> b >> s;
	for (i = 0; i < n; i++) {
		if (s[i] == 'a') {
			if (ct < a + b) {
				cout << "Yes\n";
				ct++;
			}
			else cout << "No\n";
		}
		else if (s[i] == 'b') {
			cbb++;
			if ((ct < a + b) && (cbb <= b)) {
				cout << "Yes\n";
				ct++;
			}
			else cout << "No\n";
		}
		else cout << "No\n";
	}

	return 0;
}


