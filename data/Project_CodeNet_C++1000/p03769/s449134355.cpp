#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205, MAXM = 45;

long long n;

long long C[MAXM][MAXM];
int v[MAXM];

int main()
{
	cin >> n;
	long long cur = 0;
	int len;
	for (int i = 1; ; i++) {
		if ((1ll<<(i-1))-1 <= n) cur = (1ll<<(i-1))-1, len = i;
		else break;
	}
	C[0][0] = 1;
	for (int i = 1; i <= len; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i-1][j]+C[i-1][j-1];
	}
	n -= cur;
	int pos = len/2;
	for (int i = pos; i >= 0; i--) {
		while (n >= C[len][i])
			v[i]++, n -= C[len][i];
	}
	int cnt = 0;
	for (int i = 0; i <= pos; i++) {
		cnt += v[i];
	}
	if (cnt*2+len > 200) throw;
	cout << cnt*2+len << endl;
	for (int i = 0, cur = cnt; i < len; i++) {
		while (v[i]) {
			cout << (cur--) << " ";
			v[i]--;
		}
		cout << cnt+1 << " ";
	}
	for (int i = 1; i <= cnt; i++)
		cout << i << " ";
	cout << endl;
	return 0;
}
