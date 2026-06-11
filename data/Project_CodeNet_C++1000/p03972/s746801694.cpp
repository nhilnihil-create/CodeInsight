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
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };


int main() {
	int w, h;
	cin >> w >> h;
	vector<pair<ll,int>>edges;

	rep(i, 0, w) {
		ll p;
		cin >> p;
		edges.pb({p,0});
	}

	rep(i, 0, h) {
		ll q;
		cin >> q;
		edges.pb({ q,1 });
	}

	sort(all(edges));

	w++;
	h++;

	ll ans = 0;
	fore(e,edges) {
		if (e.second == 0) {
			ans += h*e.first;
			w--;
		}
		else {
			ans += w * e.first;
			h--;
		}
	}

	cout << ans << endl;


	return 0;
}