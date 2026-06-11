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
	deque<int> dq;
	rep(i, n) {
		int a;
		cin >> a;
		if (i==0) dq.push_back(a);
		else if (n%2==0) {
			if (i%2==1) dq.push_front(a);
			else dq.push_back(a);
		}
		else if (n%2==1) {
			if (i%2==1) dq.push_back(a);
			else dq.push_front(a);
		}
	}
	rep(i, n) cout << dq.at(i) << " ";
}