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
#include <deque>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int n;
	cin >> n;
	int A[n];
	rep(i, n) cin >> A[i];
	set<int> s;
	int cnt = 0;
	rep(i, n) {
		if (A[i] <= 399) s.insert(1);
		else if (A[i] <= 799) s.insert(2);
		else if (A[i] <= 1199) s.insert(3);
		else if (A[i] <= 1599) s.insert(4);
		else if (A[i] <= 1999) s.insert(5);
		else if (A[i] <= 2399) s.insert(6);
		else if (A[i] <= 2799) s.insert(7);
		else if (A[i] <= 3199) s.insert(8);
		else cnt++;
	}
	int mn = max(int(s.size()), 1);
	int mx = s.size();
	if (cnt!=0) mx = mx + cnt;
	cout << mn << " " << mx << endl;
}