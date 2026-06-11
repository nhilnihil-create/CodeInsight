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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD  998244353
#define REP(i,n) for(long long i = 0;i < n;++i)
long long inv(long long now) {
	long long ans = 1;
	long long te = MAX_MOD - 2LL;
	while (te != 0) {
		if (te % 2 == 1) {
			ans *= now;
			ans %= MAX_MOD;
		}
		te /= 2;
		now *= now;
		now %= MAX_MOD;
	}
	return ans;
}
int main(){
	long long n;
	cin >> n;
	vector<long long> solve;
	solve.push_back(1);
	n--;
	for (long long i = 1;n != 0; ++i) {
		for (long long q = i; q >= 0; --q) {
			if (q < 50 && (1LL << (long long)q) <= n) {
				n -= (1LL << (long long)q);
				solve.insert(solve.begin() + q, i + 1);
				break;
			}
		}
	}
	cout << solve.size() + 100 << endl;
	REP(i, solve.size()) {
		cout << solve[i] << " ";
	}
	for (int i = 1; i <= 100; ++i) {
		cout << i << " ";
	}
	cout << endl;
}