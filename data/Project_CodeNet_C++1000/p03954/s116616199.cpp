#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
#include <complex>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
vector<int> geko;
int solve(int now) {
	vector<int> newer;
	REP(i, geko.size()) {
		if (geko[i] >= now) {
			if (i == 0 || i == geko.size() - 1) newer.push_back(1);
			newer.push_back(1);
		}
		else {
			if (i == 0 || i == geko.size() - 1) newer.push_back(0);
			newer.push_back(0);
		}
	}
	int itr[2] = { 10000000,100000000};
	int ans[2] = {};
	int mid = newer.size() / 2;
	for (int i = mid-1; i >= 0; --i) {
		if (newer[i] == newer[i + 1]) {
			itr[0] = i;
			ans[0] = newer[i];
			break;
		}
	}
	for (int i = mid+1; i < newer.size(); ++i) {
		if (newer[i] == newer[i - 1]) {
			itr[1] = i;
			ans[1] = newer[i];
			break;
		}
	}
	if (abs((int)newer.size()/2 - itr[0]) > abs((int)newer.size()/2 - itr[1])) {
		return ans[1];
	}
	else {
		return ans[0];
	}
}
int main() {
	int n;
	cin >> n;
	REP(i, 2 * n - 1) {
		int a;
		cin >> a;
		geko.push_back(a);
	}
	int bot = 1;
	int top = 2 * n;
	while (top - bot > 1) {
		int mid = (top + bot) / 2;
		if (solve(mid) == 1) {
			bot = mid;
		}
		else {
			top = mid;
		}
	}
	cout << bot << endl;
}
