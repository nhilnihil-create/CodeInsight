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
const int N = 5000;
LL dp[N + 5][N + 5];
int n, pressed;

LL solve(int idx,int mv) {
	if(mv == pressed) return idx == n; //when all moves already used, check whether the string is same or not
	LL &res = dp[idx][mv];
	if(res != -1) return res;
	res = solve(idx + 1, mv + 1); //pressed (maybe) the right character
	if(idx != 0) res += 2 * solve(idx - 1, mv + 1); //remove one character (either is true or not)
	else res += solve(idx, mv + 1); //when there are no characters left
	return res %= MOD;
}

void hora(int tc) {
	string s;
	cin>>pressed;
	cin>>s;
	n = s.size();
	memset(dp, -1, sizeof dp);
	cout<<solve(0, 0)<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


