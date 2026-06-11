#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	int A[100];
	rep(i, n) cin >> A[i];

	sort(A, A+n, greater<int>());
	int res = accumulate(A, A+k, 0);
	cout << res << endl;
}