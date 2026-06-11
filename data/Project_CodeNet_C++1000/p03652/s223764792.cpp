#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, m;
int a[310][310];
bool out[310];

int ans;

void calc(int i){
	map<int, int> cnt;
	rep(i,n){
		int id = -1;
		rep(j,m){
			if(out[a[i][j]]) continue;
			id = a[i][j];
			break;
		}
		cnt[id]++;
	}
	int maxV = 0, maxI = -1;
	for(auto p : cnt){
		if(maxV < p.second){
			maxV = p.second;
			maxI = p.first;
		}
	}
	chmin(ans, maxV);
	if(i == m) return;
	out[maxI] = true;
	calc(i+1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,n)rep(j,m) cin >> a[i][j];
    ans = 114514;
    calc(1);
    cout << ans << endl;
    return 0;
}