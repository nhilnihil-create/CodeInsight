#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int N, A;
	cin >> N >> A;
	vector<int> x(N);
	for (int i = 0; i < N; ++i)cin >> x[i];

	ll dp[55][3000][55]; 
	//3次元のdpを作る。dp[ i ][ s ][ k ] := N 個の整数のうちの最初の i 個から、k 個選ぶ場合について、総和を s にするものが何個あるか
	memset(dp, 0, sizeof(dp)); //0で初期化
	
	dp[0][0][0] = 1; //最初を1にする？？？「何も選ばない」を除くため？？

	for (int i = 0; i < N; ++i) //「最初のi個から」をカード分繰り返す
	{
		for (int s = 0; s <= N * A; ++s) //「総和s」を0から（カードの枚数 * 平均）まで繰り返す。 S / K(<=N) = A 変換するとsの最大値が分かる
		{
			for (int k = 0; k <= N; ++k) //「k個選ぶ」をカードの枚数分繰り返す
			{
				if (dp[i][s][k] == 0) continue; 
				dp[i + 1][s][k] += dp[i][s][k]; //x(i)を選ばない場合、iを次に移動するだけ
				dp[i + 1][s + x[i]][k + 1] += dp[i][s][k]; //x(i)を選んだ場合、iを次に移動して、総和sにx[i]を加算して、選んだ個数kを加算する
			}
		}
	}

	// ここまでで準備ができたのであとは答えを出力

	ll res = 0;
	for (int k = 1; k <= N; ++k) res += dp[N][A * k][k]; //「k個選ぶ」をカードの枚数分繰り返す。N枚のカードからk個選んで総和がA*kになるものを加算する。
	cout << res << endl;
}