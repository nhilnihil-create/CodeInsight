#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N, M; cin >> N >> M;
	vector<string> A(N), B(M);
	string ans = "No";
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < M; i++) cin >> B[i];
	if(A == B) ans = "Yes";
	else {
		for(int i = 0; i <= N - M; i++) {
			for(int j = 0; j <= N - M; j++) {
			vector<string> Apart(M);
			for(int k = 0; k < M; k++) Apart[k] = A[i + k].substr(j, M);
			if(Apart == B) ans = "Yes";
			}
		}
	}
	cout << ans << endl;
	return 0;
}