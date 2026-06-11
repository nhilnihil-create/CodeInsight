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
#include <stack>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int n, m;
	cin >> n >> m;
	int A[m], B[m];
	rep(i, m) cin >> A[i] >> B[i];
	set<int> s;
	rep(i, m) {
		if (A[i]==1) s.insert(B[i]);
	}
	rep(i, m) {
		if (B[i]==n) {
			if (s.count(A[i])) {
				cout << "POSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}