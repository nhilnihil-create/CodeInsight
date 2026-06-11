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
long long swappings[70][100001];
long long final_swappings[100001];

int main(){
#define int long long
	int n;
	cin >> n;
	vector<long long> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
		swappings[0][i] = i;
		final_swappings[i] = i;
	}
	long long m, k;
	cin >> m >> k;
	REP(i, m) {
		int a;
		cin >> a;
		a--;
		swap(swappings[0][a], swappings[0][a - 1]);
	}
	for (int q = 1; q <= 64; ++q) {
		REP(i, n) {
			swappings[q][i] = swappings[q - 1][swappings[q - 1][i]];
		}
	}
	for (long long q = 0; q <= 62; ++q) {
		if (((1LL << q) & k) != 0) {
			REP(i, n) {
				final_swappings[i] = swappings[q][final_swappings[i]];
			}
		}
	}
	cout << inputs[0] << endl;
	long long now = inputs[0];
	REP(i,n-1) {
		int a = final_swappings[i];
		int diff = inputs[a + 1] - inputs[a];
		now += diff;
		cout << now << endl;
	}
}