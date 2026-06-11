#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int p[100001];
	rep(i,100001) p[i] = 0;
	rep(i,N) {
		int a;
		cin >> a;
		p[a]++;
	}
	int ans = 0;
	for (int i = 1; i < 100000; i++) {
		int psum = p[i-1] + p[i] + p[i+1];
		ans = max(ans, psum);
	}
	cout << ans << endl;
	return 0;
}
