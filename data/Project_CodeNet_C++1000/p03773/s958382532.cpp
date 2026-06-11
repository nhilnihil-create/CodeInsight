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
	int A, B;

	cin >> A >> B;

	int ans = A + B;

	if (ans >= 24) cout << ans - 24 << endl;
	else cout << ans << endl;

}