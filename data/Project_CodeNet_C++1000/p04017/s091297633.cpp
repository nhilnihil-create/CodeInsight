#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll L, x[100000];
ll dp[100000][18];//use DOUBLING
//100000 <= 2^17

void doubling() {
	//しゃくとりでまずDPテーブルの初期化をする
	
	int r = 0;
	for (int l = 0; l < N; l++) {
		//[L, R)
		while (x[r] - x[l] <= L && r < N) {
			r++;
		}
		dp[l][0] = r - 1;
		
		if (l == r)r++;
	}
	for (int j = 1; j < 18; j++) {
		for (int i = 0; i < N; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> x[i];
	cin >> L;

	doubling();
	
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (r < l)swap(l, r);
		int ans = 0;
		int cur = l;
		for (int j = 17; j >= 0; j--) {
			if(dp[cur][j] < r){
				cur = dp[cur][j];
				ans += (1 << j);
			}
		}
		ans++;//1ズレは上の式では対応不可能
		cout << ans << endl;
	}

	return 0;
}