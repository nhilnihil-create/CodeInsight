
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <iostream>
#include <string>
#include <set>
#include <map>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

int A[SIZE], B[SIZE];

int main()
{
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
	ll ret = 0;

	//そのままのkを対象にして計算した結果
	for (int i = 0; i < n; i++) if ((k | A[i]) == k) ret += B[i];

	//kの各ビットに対して
	for (int i = 0; i <= 30; i++)
	{
		//kのうちビットが立ってない桁は無視
		if (!(k >> i & 1)) continue;

		ll now = 0;
		//注目してるkのビットより下を1で埋める
		for (int j = 0; j < i; j++) now |= 1 << j;

		//iより上位をkと一緒にする
		for (int j = i + 1; j <= 30; j++) if (k >> j & 1) now |= 1 << j;

		//集計開始
		ll sum = 0;

		//すべてのA[i]に対して Krに含まれるものを集計する
		for (int j = 0; j < n; j++) if ((now | A[j]) == now) sum += B[j];

		//このKrの結果を使って更新
		ret = max(ret, sum);
	}
	cout << ret << endl;
	return 0;
}
