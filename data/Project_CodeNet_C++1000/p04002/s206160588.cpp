#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll h, w, n, x, y, ans[10];
set<pair<ll, ll>> b;

int main(){
	cin >> h >> w >> n;
	for(ll i = 1; i <= n; i++){
		cin >> y >> x;
		b.insert(make_pair(x, y));
	}
	memset(ans, 0, sizeof(ans));
	
	for(auto itr = b.begin(); itr != b.end(); itr++){
		x = (*itr).first;
		y = (*itr).second;
		for(ll i = max(x-1, 2LL); i <= min(x+1, w-1); i++){
			for(ll j = max(y-1, 2LL); j <= min(y+1, h-1); j++){
				int cnt = 0;
				for(ll mi = i-1; mi <= i+1; mi++){
					for(ll mj = j-1; mj <= j+1; mj++){
						if(b.find(make_pair(mi, mj)) != b.end()){cnt++;}
					}
				}
				ans[cnt]++;
			}
		}
		//cout << x << y << endl;
	}
	
	ans[0] = (h-2)*(w-2);
	for(ll ai = 1; ai <= 9; ai++){
		ans[ai] /= ai;
		ans[0] -= ans[ai];
	}
	for(ll ai = 0; ai <= 9; ai++){cout << ans[ai] << endl;}
	return 0;
}