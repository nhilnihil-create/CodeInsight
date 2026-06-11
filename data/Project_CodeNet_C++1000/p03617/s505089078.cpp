#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int Q, H, S, D;
	long long N;
	cin >> Q >> H >> S >> D >> N;

	long long ans = 0;
	int one = min(Q * 4, min(H * 2, S));
	if (one * 2 > D){
		ans += (N / 2) * D;
		N = N % 2;
	}
	ans += N * one;
	cout << ans << endl;
}