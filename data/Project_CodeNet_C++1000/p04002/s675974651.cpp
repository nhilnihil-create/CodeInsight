#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

signed main(){
	int H, W, N;
	cin >> H >> W >> N;
	set<pair<int,int>> st;
	for(int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		st.insert(make_pair(a,b));
	}
	vector<int> res(10);
	for(auto p: st) {
		for(int i = -2; i <= 0; ++i) for(int j = -2; j <= 0; ++j) {
			if(p.first + i <= 0 || H < p.first + i + 2) continue;
			if(p.second + j <= 0 || W < p.second + j + 2) continue;
			int cnt = 0;
			for(int k = 0; k < 3; ++k) for(int l = 0; l < 3; ++l) {
				int r = p.first + i + k, c = p.second + j + l;
				if(st.find(make_pair(r,c)) != st.end()) {
					++cnt;
				}
			}
			if(cnt > 0) {
				res[cnt]++;
			}
		}
	}
	res[0] = (H - 2) * (W - 2);
	for(int i = 1; i < 10; ++i) {
		res[i] /= i;
		res[0] -= res[i];
	}
	for(int i = 0; i < 10; ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
