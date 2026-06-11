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
	int S[n];
	int sum = 0;
	rep(i, n) {
		cin >> S[i];
		sum += S[i];
	}
	sort(S, S+n);
	if (sum%10==0) {
		bool flg = false;
		rep(i, n) {
			if (S[i]%10!=0) {
				sum -= S[i];
				flg = true;
				break;
			}
		}
		if (!flg) sum = 0;
	}
	cout << sum << endl;
}