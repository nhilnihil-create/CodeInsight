#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int mod = 1e9 + 7;

int n, dp[N][N];
string s;

void add(int &x, int y){
	x += y;
	if (x >= mod){
		x -= mod;
	}
}

int rec(int pos, int sisa){
	if (!sisa){
		return !pos;
	}
	if (pos == N){
		return 0;
	}
	int &ret = dp[pos][sisa];
	if (ret != -1){
		return ret;
	}
	ret = rec(max(0, pos-1), sisa-1);
	add(ret, 2 * rec(pos+1, sisa-1) % mod);
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	cout << rec((int)s.size(), n) << "\n";
}