#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-6;

int mod = 1000000000 + 7;
int a[110000];
int main()
{
	int n;
	scanf("%d", &n);
	int all = 0;
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if ((i - all) * 2 - 1 > a[i]) {
			ret = ret * (long long)(i - all) % mod;
			all++;
		}
	}
	while (all < n) {
		ret = ret * (long long)(n - all) % mod;
		all++;
	}
	printf("%d\n", ret);
}

