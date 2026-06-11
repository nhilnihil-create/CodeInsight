// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 305;

long long a[N][N], b[N][N], c[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j];
			if(i<j) sum += a[i][j];
		}
	}

	priority_queue< pair<long long, pair<int,int>> > pq;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			pq.push(make_pair(a[i][j], make_pair(i, j)));
		}
	}
	while(!pq.empty()) {
		auto now = pq.top();
		pq.pop();
		pair<int,int> pos = now.second;
		long long val = now.first;
		if(a[pos.first][pos.second] != val) continue;
		long long mn = 1e15;
		for(int j = 0; j < n; j++) {
			if(j == pos.first || j == pos.second) continue;
			mn = min(mn, a[pos.first][j] + a[j][pos.second]);
		}
		if(mn == val) {
			sum -= val;
			a[pos.first][pos.second] = 1e15;
			a[pos.second][pos.first] = 1e15;
		}
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != b[i][j]) {
				cout << -1;
				exit(0);
			}
		}
	}

	cout << sum;

	return 0;
}
