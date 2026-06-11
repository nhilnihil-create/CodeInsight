#include <iostream>
#include <algorithm>
#include <vector>
//#include <queue>

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define debug(vec) for(auto v : vec) cout << v << " "; cout << endl;

using namespace std;

typedef long long int llint;

const long long int INF = 1 << 30; //10^10
const llint MOD = 998244353;

inline void maxch(int& a, int b) {if (a < b) a = b;}

int main() {
llint n, w;
cin >> n >> w;
vector<pair<int,int>> wv(n);
rep(i,n) cin >> wv[i].first >> wv[i].second;

sort(wv.begin(), wv.end(), greater<pair<int, int>>());

llint w1 = wv[n-1].first;

vector<vector<int>> wv4(4,vector<int>());
rep(i, n) {
  rep(j,4) if (wv[i].first == w1 + j) wv4[j].push_back(wv[i].second);
}
vector<int> k(4,-1);
llint ans = 0, k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3]; 

for (k[0] = k0; k[0] < (int)wv4[0].size(); k[0]++) {
	for (k[1] = k1; k[1] < (int)wv4[1].size(); k[1]++) {
		for (k[2] = k2; k[2] < (int)wv4[2].size(); k[2]++) {
			for (k[3] = k3; k[3] < (int)wv4[3].size(); k[3]++) {
				if ((llint)(1+k[0]) * w1 + (1+ k[1]) * (w1 + 1) + (1+k[2]) * (w1 + 2) + (1+ k[3]) * (w1 + 3) <= w) {
				  llint tmp = 0;
					rep(j,4) rep(i, k[j]+1) tmp += wv4[j][i];
					//cout << tmp << endl;
					ans = max(ans, tmp);
				}
			}
		}
	}
}

cout << ans << endl;
}

// vector<vector<pair<int,int>>> edge = { {{1,1},{2,2},{3,10}}, {{3,3}}, {{3,4}}, {} }; //(0,1),(0,2),(0,3),(1,3),(2,3)
