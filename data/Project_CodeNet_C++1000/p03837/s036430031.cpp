#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;
const int MAX_N = 100;

int d[MAX_N][MAX_N];
int N;

int warchall_floyd(){
	rep(k, N) rep(i, N) rep(j, N)
	d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int M;
	cin >> N >> M;
	rep(i,N)rep(j,N){
		d[i][j] = INF;
		if(i == j) d[i][j] = 0;
	}
	int a[M], b[M], c[M];
	rep(i,M){
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
		d[a[i]][b[i]] = c[i];
		d[b[i]][a[i]] = c[i];
	}
	warchall_floyd();
	int ans = 0;
	rep(i,M){
		if(d[a[i]][b[i]] < c[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}