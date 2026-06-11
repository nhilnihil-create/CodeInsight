#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	int N, K;
	cin >> N >> K;
	int ans = K;
	rep2(i, N, 1, 1){
		ans *= (K - 1);
	}
	cout << ans << endl;
}