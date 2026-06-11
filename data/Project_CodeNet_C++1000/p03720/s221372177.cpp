#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int road[N+1];
	rep(i,N+1) road[i] = 0;
	rep(i,M) {
		int a, b;
		cin >> a >> b;
		road[a]++; road[b]++;
	}
	for (int i = 1; i <= N; i++) {
		cout << road[i] << endl;
	}

	return 0;
}
