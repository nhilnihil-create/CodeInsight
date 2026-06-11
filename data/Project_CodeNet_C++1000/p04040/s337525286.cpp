////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const LL MOD = 1e9 + 7;
const int N = 2e5 + 5;
LL fct[N + 5], inv[N + 5];

LL fast(LL A,LL B){
	LL res = 1;
	while(B) {
		if(B&1) res = res * A % MOD;
		B /= 2;
		A = A * A % MOD;
	}
	return res;
}

void pre() {
	fct[0] = 1;
	for(int i = 1;i <= N;i++) fct[i] = fct[i-1] * i %  MOD;
	inv[N] = fast(fct[N], MOD - 2);
	for(int i = N - 1;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

LL combin(int n, int r) {
	if(n < r) return 0;
	return fct[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void hora(int tc) {
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	LL ways = combin(h - 1 + w - 1, h - 1);
	LL red = combin(h - a + b - 1, b - 1) * combin(a - 1 + w - b, w - b) % MOD;
	for(int i = b - 1;i >= 1;i--) {
		if(a != 1) red = (red + combin(h - a + i - 1, i - 1) * combin(a - 2 + w - i, w - i))% MOD;
	}
	cout<<(ways + MOD - red) % MOD<<endl;
}

int main(){
	desperate_optimization(10);
	pre();
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


