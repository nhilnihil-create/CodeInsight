
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



int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll>a(n); vector<ll>b(n);

	rep(i, 0, n) {
		cin >> a[i] >> b[i];
	}


	ll ans = -1;
	for (int i = 0; i <= 35; i++) {
		ll msk = 0;
		if (i == 0)msk = k;
		else {
			if ((1LL << i)&k) {
				for (int j = 0; j <= 35; j++) {
					if (j < i)msk += 1LL << j;
					else if (j > i && (k & (1LL << j)))msk += 1LL << j;
				}
			}
			else {
				continue;
			}
		}

		ll temp = 0;
		rep(p, 0, n) {
			int ok = 1;
			for (int j = 0; j <= 35; j++) {
				if ( ((1LL << j)&a[p]) && !((1LL << j)&msk) ) {
					ok = 0;
				}
			}
			if (ok)temp += b[p];
		}
		ans = max(ans, temp);
	}

	cout << ans << endl;

	return 0;
}