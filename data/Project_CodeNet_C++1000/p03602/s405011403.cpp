
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };



ll n;
ll dist_1[305][305];
bool dist_2[305][305];


int main() {
	cin >> n;

	rep(i, 0, n)rep(j, 0, n) {
		ll x;
		cin >> x;
		dist_1[i][j] = x;
		dist_2[i][j] = true;
	}
	
	rep(i, 0, n)rep(j, 0, n)rep(k, 0, n) {
		if (dist_1[i][j] > dist_1[i][k] + dist_1[k][j]) {
			cout << "-1" << endl;
			return 0;
		}
		else if (dist_1[i][j] == dist_1[i][k] + dist_1[k][j] && i != k && j != k) {
			dist_2[i][j] = false;
		}
	}

	ll ans = 0;
	rep(i, 0, n)rep(j, 0, n) {
		if (dist_2[i][j])ans += dist_1[i][j];
	}

	cout << ans / 2 << endl;


	return 0;
}