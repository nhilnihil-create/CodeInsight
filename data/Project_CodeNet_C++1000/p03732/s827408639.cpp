
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <utility> 

#define rep(i,m,n) for(ll i = m;i < n;i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 50;




int main(){
	ll N, W;
	ll w1;
	cin >> N >> W;

	vector<ll> s[4];

	rep(i, 0, N) {
		ll w, v;
		cin >> w >> v;
		if (i == 0) w1 = w;
		s[w - w1].push_back(v);
	}

	rep(i, 0, 4) {
		sort(s[i].begin(), s[i].end());
		s[i].push_back(0);
		reverse(s[i].begin(), s[i].end());
		rep (j,1,s[i].size()){
			s[i][j] += s[i][j - 1];
		}
	}




	ll ans = 0;
	rep(i,0,s[0].size()) {
		rep(j, 0, s[1].size()) {
			rep(k, 0, s[2].size()) {
				rep(l, 0, s[3].size()) {
					ll wtotal = i * w1 + j * (w1 + 1) + k * (w1 + 2) + l * (w1 + 3);
					if (wtotal <= W) {
						ll sum = s[0][i] + s[1][j] + s[2][k] + s[3][l];
						ans = max(sum, ans);
					}
				}
			}
		}
	}

	cout << ans << endl;


	return 0;
}
