#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;



signed main(){

	int N;
	string s;
	cin >> N >> s;
	string ans(N,'X');

	char t[2] = { 'S', 'W' };
	for (int i = 0; i < 2; i++){
		ans[0] = t[i];
		for (int j = 0; j < 2; j++){
			ans[1] = t[j];

			for (int n = 2; n < N; n++){
				if (s[n - 1] == 'o' && ans[n - 1] == 'S') ans[n] = ans[n-2];
				if (s[n - 1] == 'o' && ans[n - 1] == 'W') ans[n] = 'S'+'W'-ans[n-2];
				if (s[n - 1] == 'x' && ans[n - 1] == 'S') ans[n] = 'S' + 'W' - ans[n - 2];
				if (s[n - 1] == 'x' && ans[n - 1] == 'W') ans[n] = ans[n - 2];
			}

			char zero;
			if (s[N - 1] == 'o' && ans[N - 1] == 'S') zero = ans[N - 2];
			if (s[N - 1] == 'o' && ans[N - 1] == 'W') zero = 'S' + 'W' - ans[N - 2];
			if (s[N - 1] == 'x' && ans[N - 1] == 'S') zero = 'S' + 'W' - ans[N - 2];
			if (s[N - 1] == 'x' && ans[N - 1] == 'W') zero = ans[N - 2];

			if (zero == ans[0]){
				char one;
				if (s[0] == 'o' && ans[0] == 'S') one = ans[N - 1];
				if (s[0] == 'o' && ans[0] == 'W') one = 'S' + 'W' - ans[N - 1];
				if (s[0] == 'x' && ans[0] == 'S') one = 'S' + 'W' - ans[N - 1];
				if (s[0] == 'x' && ans[0] == 'W') one = ans[N - 1];

				if (one == ans[1]){
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}