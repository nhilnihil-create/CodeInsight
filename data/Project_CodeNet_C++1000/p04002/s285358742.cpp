#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	int dx[] = {-2, -1, 0}, dy[]  = {-2, -1, 0};
	int h, w, n;
	cin >> h >> w >> n;
	map<pair<int ,int>, long long> mp;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(a + dx[j] >= 1 && a + dx[j] <= h - 2 && b + dy[k] >= 1 && b + dy[k] <= w - 2) {
					mp[make_pair(a + dx[j], b + dy[k])]++;
				}
			}
		}
	}                   		
						/*for(auto i : mp) {
							cerr << i.first.first << " " << i.first.second << " " << i.second << endl;
						}*/
	vector<long long> ans(10);
	long long nonz = 0;
	for(int i = 9; i > 0; i--) {
		for(auto j : mp) {
			if(j.second == i) {
				ans[i]++;
				nonz++;
			}
		}
	}
	ans[0] = 1LL * (h - 2) * 1LL * (w - 2) - nonz;
	for(int i = 0; i < 10; i++) {
		cout << ans[i] << '\n';
	}
	return 0;	
}
