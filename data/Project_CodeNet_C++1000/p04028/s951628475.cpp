#include<iostream>
#include<cstdint>
using namespace std;

const int MAX = 5100;
const int MOD = 1000000007; // 今回使う余り

int main() {
	int N;
	string s;
	cin >> N >> s;
	static int l = s.size(), dp[MAX][MAX]; // dp[i][j] = i文字入力した時点でj文字が表示される通り数
	for (int i = 0;i < N;i ++) dp[0][i] = 0;
	dp[0][0] = 1;
	for (int i = 1;i <= N;i ++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
		for (int j = 1;j <= N;j ++) {
			dp[i][j] = (2 * dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1]) % MOD;
		}
	}
	// ここでdp[N][l]は求めたい文字列……だけじゃなく余計なパターンが入っているので、正しいパターンは2^lで割った値
	int64_t rev = (MOD + 1) >> 1; // この値に対し2倍するとMOD + 1、だからこれは逆元
	
	int ans = dp[N][l];
	for (int i = 0;i < l;i ++) ans = (ans * rev) % MOD;
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

まず、求めたい文字列の長さになる組み合わせは動的計画法を用いて解くことができるね
この時、出てきた文字列って0000…から1111…の全ての組み合わせの総和じゃん？
各確率は独立かつ等しいので、2^lで割れば答え出るじゃん
*/