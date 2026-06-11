#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <stdio.h>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {
	int x, a, b;

	cin >> x >> a >> b;
	if (abs(x - a) > abs(x - b))cout << "B" << endl;
	else cout << "A" << endl;
}