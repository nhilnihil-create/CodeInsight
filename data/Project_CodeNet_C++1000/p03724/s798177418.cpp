#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector <int> v(N);
	for (int ii = 0; ii < M; ++ii){
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a]++;
		v[b]++;
	}

	bool ok = true;
	for (int ii = 0; ii < N; ++ii){
		if (v[ii]%2==1){
			ok = false;
			break;
		}
	}

	if (ok){
		cout << "YES" << endl;
	} else {	
		cout << "NO" << endl;
	}

	return 0;
}
