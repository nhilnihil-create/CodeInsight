#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int road[N+1][N+1];
	rep(i,N+1)rep(j,N+1) road[i][j] = 0;
	rep(i,M) {
		int a, b;
		cin >> a >> b;
		road[a][b] += 1;
		road[b][a] += 1;
	}
	for (int i = 1; i <= N; i++) {
		int tot = 0;
		for (int j = 1; j <= N; j++) {
			tot += road[i][j];
		}
		cout << tot << endl;
	}
	return 0;
}
