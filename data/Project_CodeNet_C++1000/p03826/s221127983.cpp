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
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int ans1 = A * B, ans2 = C * D;

	if (ans1 >= ans2) cout << ans1 << endl;
	else cout << ans2 << endl;
	
}