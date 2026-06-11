////////////////////////////////////////////
///                                      ///
///        Template ver. 1.2. rapel      ///
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

#define F first
#define S second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 300;
int arr[N + 5][N + 5];
int id[N + 5];
int mark[N + 5];
int occ[N + 5];

vector<int> who[N + 5];
priority_queue<pair<int,int> > pq;

void hora(int tc) {
	int n, m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cin>>arr[i][j];
		id[i] = 2;
		occ[arr[i][1]]++;
		who[arr[i][1]].pb(i);
	}
	int result = 0;
	for(int i = 1;i <= m;i++) {
		pq.push({occ[i], i});
		result = max(result, occ[i]);
	}
	while(!pq.empty()) {
		while(!pq.empty() && (mark[pq.top().S ]== 1 || occ[pq.top().S] != pq.top().F)) pq.pop();
		if(!pq.empty()) {
			int idx = pq.top().S;
			pq.pop();
			mark[idx] = 1;
			for(auto x: who[idx]) {
				for( ; id[x] <= m; ) {
					int val = arr[x][id[x]];
					id[x]++;
					if(mark[val] == 1) continue;
					who[val].pb(x);
					occ[val]++;
					pq.push({occ[val], val});
					break;
				}
			}
			while(!pq.empty() && (mark[pq.top().S ]== 1 || occ[pq.top().S] != pq.top().F)) pq.pop();
			if(pq.empty()) break;
			result = min(result, pq.top().F);
		}
	}
	cout<<result<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
