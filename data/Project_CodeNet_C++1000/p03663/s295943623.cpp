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
	LL keta;
	LL flag=false;

	for (keta = 1;keta<=1000000000; keta *= 10) {
		cout << "? " << keta << endl;
		fflush(stdout);
		char s;
		cin >> s;
		if (s == 'N') {
			flag = true;
			keta /= 10;
			break;
		}
	}
	if (flag) {

		LL upper = keta * 10 - 1;
		LL lower = keta;

		LL count = 0;
		while (lower < upper)
		{
			count++;
			if (count == 50) {
				break;
			}
			LL mid = ((upper + lower) / 2) * 10;
			cout << "? " << mid << endl;
			fflush(stdout);

			char s;
			cin >> s;
			if (s == 'Y') {
				upper = mid / 10;
			}
			else {
				lower = mid / 10 + 1;
			}
		}

		cout << "! " << lower << endl;
		fflush(stdout);
	}
	else {
		for (keta = 2; keta <= 2000000000; keta *= 10) {
			cout << "? " << keta << endl;
			fflush(stdout);
			char s;
			cin >> s;
			if (s == 'Y') {
				cout << "! " << keta/2 << endl;
				fflush(stdout);
			}
		}
	}

}
