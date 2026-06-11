#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>

using namespace std;
typedef long long int LL;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int xcomp(vector<LL>& a, vector<LL>& b) {
	return a[0] < b[0];
}

#define XSORT(c) sort((c).begin(),(c).end(),xcomp)

#define ALL(x) (x).begin(),(x).end()
LL mod = 1000000007;

int main() {
	LL N;
	cin >> N;
	vector<LL> x(N, 0);
	REP(i, N) {
		cin >> x[i];

	}
	LL sum = 1;
	REP(i, x.size()) {
		if (x[i] <= 2 * i) {
			sum *= i + 1;
			sum = sum%mod;
			x.erase(x.begin());
			i--;
		}
	}
	REP(i, x.size()) {

		sum *= i + 1;
		sum = sum%mod;
	}
	cout << sum%mod << endl;
}
