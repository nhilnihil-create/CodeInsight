#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int ans = 0;

	ans = min(a + b, a + c);
	ans = min(ans, b + c);

	cout << ans << endl;

}