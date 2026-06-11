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

const int N = 1e5;
const int DD = 10;
int visit[DD + 2][N + 5];

vector<int> lst[N + 5];

int V[N + 5], D[N + 5], C[N + 5];
queue<pair<int,int> > q;

void hora(int tc) {
	int n, m;
	cin>>n>>m;
	while(m--) {
		int u, v;
		cin>>u>>v;
		lst[u].pb(v), lst[v].pb(u);
	}
	int Q;
	cin>>Q;
	for(int i = 0;i < Q;i++) cin>>V[i]>>D[i]>>C[i];
	memset(visit, -1, sizeof visit);
	for(int i = Q - 1;i >= 0;i--) {
		int start = V[i];
		int step = D[i];
		int col = C[i];
		if(visit[step][start] != -1) continue;
		visit[step][start] = i;
		q.push({step, start});
		while(!q.empty()) {
			int step = q.front().F;
			int pos = q.front().S;
			q.pop();
			if(step == 0) continue;
			for(int x: lst[pos]) {
				if(visit[step - 1][x] != -1) continue;
				visit[step - 1][x] = i;
				q.push({step - 1, x});
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		int maxi = -1;
		for(int j = 0;j <= DD;j++) maxi = max(maxi, visit[j][i]);
		if(maxi == -1) cout<<0<<endl;
		else cout<<C[maxi]<<endl;
	}
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
