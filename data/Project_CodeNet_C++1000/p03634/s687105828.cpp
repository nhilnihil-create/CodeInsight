#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> v(n);
	REP(i,n-1){
		int a,b,c;
		cin >> a >> b >> c;
		a--; b--;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	int q,k;
	cin >> q >> k;
	k--;
	vector<vector<int>> a(q,vector<int>(2));
	REP(i,q){
		cin >> a[i][0] >> a[i][1];
		a[i][0]--;
		a[i][1]--;
	}
	
	queue<int> que;
	vector<ll> cost(n,-1);
	que.push(k);
	cost[k] = 0;
	while(!que.empty()){
		int now = que.front();
		que.pop();
		
		for(auto x: v[now]){
			int child = x.first;
			int c = x.second;
			if(cost[child]==-1){
				cost[child] = cost[now] + c;
				que.push(child);
			}
		}
	}
	
	REP(i,q){
		cout << cost[a[i][0]]+cost[a[i][1]] << endl;
	}
	
	
	return 0;
}