// 写経 of けんちょん
#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line
int N, M;
int a[1100], b[1100], c[1100];
int dist[110][110];
const int INF = 1e9;
int main()
{
	cin >> N >> M;
	rep(i,N){
		rep(j,N) dist[i][j] = INF;
		dist[i][i] = 0;
	}

	rep(i,M){
		cin >> a[i] >> b[i] >> c[i];
		--a[i], --b[i];
		dist[a[i]][b[i]] = c[i];
		dist[b[i]][a[i]] = c[i];
	}
	
	rep(k,N){
		rep(i,N){
			rep(j,N){
				chmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < M; i++){
		if(c[i] > dist[a[i]][b[i]]) ++res;
	}
	cout << res << endl;
}
