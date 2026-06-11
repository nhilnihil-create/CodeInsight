#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF (1<<20)

int main() {
	int N, T;
	cin >> N >> T;
	vector<int> A(N), B;
	map<int, bool> m;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		m[A[i]]=true;
	}
	B = A;
	sort(B.rbegin(), B.rend());

	vector<int> d(N); int j=0;
	for (int i = 0; i < N-1; i++) {
		m[A[i]]=false;
		while(!m[B[j]]) j++;
		d[i] = B[j] - A[i];
		//cout << d[i] <<" "<< B[j] << endl;
	}
	sort(d.rbegin(), d.rend());

	int ans=0, mx=d[0];
	for (int i = 0; i < d.size(); i++) {
		if(mx!=d[i]) break;
		ans++;
	}
	
	cout << ans << endl;
}

