#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N,K; cin >> N >> K;

	vector<int> l(N,0);
	for (int i = 0; i < N; i++) {
		cin >> l[i];	
	}
	sort(l.begin(),l.end());
	reverse(l.begin(),l.end());

	int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += l[i];
	}
	cout << ans << endl;

	return 0;
}
