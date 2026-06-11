#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;


int main() {
	int n;
	int x = 0, maxi = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I')x++;
		else if (s[i] == 'D')x--;

		if (x > maxi)maxi = x;
	}
	cout << maxi << endl;
	return 0;
}