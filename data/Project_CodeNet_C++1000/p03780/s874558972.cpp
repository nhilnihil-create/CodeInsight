#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
vector<int> ar;
int n, k;
int judge(int border) {
	if (ar[border] >= k) return 0;
	int gogo[6000] = {};
	gogo[0] = 1;
	for (int i = 0;i < n;++i) {
		if (i != border) {
			for (int q = k - 1;q >= 0;--q) {
				if (q + ar[i] < k) {
					gogo[q + ar[i]] |= gogo[q];
				}
			}
		}
	}
	for (int i = k - ar[border];i < k;++i) {
		if (gogo[i]) return 0;
	}
	return 1;
}
int main() {
	cin >> n >> k;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		ar.push_back(tmp);
	}
	sort(ar.begin(), ar.end());
	int bot = 0;
	int top = n - 1;
	while (top - bot > 1) {
		int mid = (top + bot) / 2;
		if (judge(mid)) {
			bot = mid;
		}
		else top = mid;
	}
	if (judge(top)) {
		cout << top+1 << endl;
		return 0;
	}
	else if (judge(bot)) {
		cout << bot+1 << endl;
	}
	else cout << 0 << endl;
	return 0;
}