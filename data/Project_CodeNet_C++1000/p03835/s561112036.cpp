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
	int K, S; cin >> K >> S;
	int Z, ans = 0;
	for(int X = 0; X <= K; X++) for(int Y = 0; Y <= K; Y++) {
		Z = S - X - Y;
		if(Z >= 0 && Z <= K) ans++;
	}
	cout << ans << endl;
	return 0;
}