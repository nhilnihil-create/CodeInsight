#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> c1, cN;
	rep(i,M) {
		int a, b;
		cin >> a >> b;
		if (a == 1) c1.push_back(b);
		if (b == N) cN.push_back(a);
	}

	vector<int> islands(N+1);
	for (int i: c1) islands[i] = 1;
	for (int i: cN) {
		if (islands[i] == 1) {
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;

	return 0;
}
