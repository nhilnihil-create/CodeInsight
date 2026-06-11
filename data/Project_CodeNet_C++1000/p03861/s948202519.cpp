#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;


int main() {
	ll a, b, x;
	cin >> a >> b >> x;
	if (a == 0) cout << b / x + 1 << endl;
	else cout << b / x - (a - 1) / x << endl;
}
