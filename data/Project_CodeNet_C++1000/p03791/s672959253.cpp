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
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	stack<int> input;
	long long ans = 1;
	REP(i, n) {
		int a;
		cin >> a;
		input.push(a);
		if (input.top() < 2 * input.size() - 1) {
			ans *= (long long)input.size();
			ans %= MAX_MOD;
			input.pop();
		}
	}
	REP(i, input.size()) {
		ans *= (long long)(i + 1LL);
		ans %= MAX_MOD;
	}
	cout << ans << endl;
	return 0;
}
