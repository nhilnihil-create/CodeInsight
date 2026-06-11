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
#include <unordered_map>
#include <set>
#include <unordered_set>
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

const int N = 1e5;
vector<int> lst[N + 5];
int depth[N + 5];

int solve(int x) {
	depth[x] = 0;
	vector<int> res;
	for(auto nx: lst[x]) res.PB(solve(nx));
	sort(res.begin(), res.end(), greater<int>());
	for(int i = 0;i < lst[x].size();i++) depth[x] = max(depth[x], res[i] + i + 1);
	return depth[x];
}

void hora(int tc) {
	int n;
	cin>>n;
	for(int i = 2;i <= n;i++) {
		int x;
		cin>>x;
		lst[x].PB(i);
	}
	cout<<solve(1)<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
