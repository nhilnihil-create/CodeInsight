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

vector<pair<LL,LL> > vec;
set<pair<LL,LL> > st, ts;
LL tot[10];

void hora(int tc) {
	LL r, c, n;
	cin>>r>>c>>n;
	pair<LL,LL> t;
	for(int i = 0;i < n;i++) {
		cin>>t.first>>t.second;
		vec.PB(t);
		st.insert(t);
	}
	LL alls = 0;
	for(auto x: st) {
		for(int i = -1;i <= 1;i++) {
			for(int j = -1;j <= 1;j++){
				int ii = x.FI + i;
				int jj = x.SE + j;
				if(ts.find({ii, jj}) != ts.end()) continue;
				if(ii <= 1 || jj <= 1 || ii >= r || jj >= c) continue;
				ts.insert({ii, jj});
				int tow = 0;
				for(int k = -1;k <= 1;k++) {
					for(int l = -1;l <= 1;l++) {
						int wi = ii + k;
						int wj = jj + l;
						if(st.find({wi, wj}) != st.end()) tow++;
					}
				}
				tot[tow]++;
				alls++;
			}
		}
	}
	tot[0] = (r - 2) * (c - 2) - alls;
	for(int i = 0;i <= 9;i++) cout<<tot[i]<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


