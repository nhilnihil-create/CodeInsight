#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(a * b, c * d);
	return 0;
}