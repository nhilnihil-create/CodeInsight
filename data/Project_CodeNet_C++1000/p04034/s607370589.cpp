#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	int s = 0;
	vector<int> V; V.assign(N, 1);
	map<int, int> mp;
	mp[0] = 1;
	for(int i=0; i<M; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		V[x]--; V[y]++;
		if(mp.count(x) != 0){
			mp[y] = 1;
			s = y;
		}
		if(V[x] == 0) mp.erase(x);
	}
	int ans = 0;
	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		int v = itr->second;
		if(v > 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}