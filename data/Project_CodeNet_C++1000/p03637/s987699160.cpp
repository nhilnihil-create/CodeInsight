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
	int n;
	cin >> n;
	int A[n];
	rep(i, n) cin >> A[i];
	int odd_cnt = 0;
	int quad_cnt = 0;
	rep(i, n) {
		if (A[i]%4==0) quad_cnt++;
		if (A[i]%2==1) odd_cnt++;
	}
	if (quad_cnt>=n/2) {
		cout << "Yes" << endl;
		return 0;
	}
	if (quad_cnt >= odd_cnt) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}