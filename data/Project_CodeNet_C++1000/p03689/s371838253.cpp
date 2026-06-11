#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

const int H = 1e6;
vector <int> gen(int N, int W) {
	if(W == N || W == 1) return {-1};
	vector <int> ret(N);
	for(int i = 0; i < N; i++) {
		if(i < W - 1) {
			ret[i] = H;
		} else if(i == W - 1) {
			ret[i] = -(W - 1) * H - 1;
		} else {
			ret[i] = ret[i % W];
		}
	}
	if(accumulate(all(ret), 0) <= 0) return {-1};
	return ret;
}
int main() {fio;
	ll H, W, h, w;
	cin >> H >> W >> h >> w;
	vector <int> G = gen(H, h);
	vector <int> R = gen(W, w);
	vector <vector <int> > ans(H, vector <int> (W, -1));
	bool r = (R[0] != -1), g = (G[0] != -1);
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			if(r) {
				ans[i][j] = R[j];
			} else if(g) {
				ans[i][j] = G[i];
			}
		}
	}

	if(!r && !g) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for(auto u : ans) {
			for(auto v : u) {
				cout << v << ' ';
			}
			cout << endl;
		}
	}
    return 0;
}