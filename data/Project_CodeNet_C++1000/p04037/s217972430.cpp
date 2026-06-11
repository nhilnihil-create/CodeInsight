#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1.1E5;
int A[MAXN];

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n = 0;
	cin >> n;
	for (int i = 1;i <= n; ++i)
		cin >> A[i];
	sort(A + 1, A + 1 + n);
	reverse(A + 1, A + 1 + n);
	
	int pos = 0;
	for (int i = 1;i <= n; ++i)
		if (A[i] >= i)
			pos = i;
	int nxt = 0;
	while (A[pos + nxt + 1] == pos)
		++nxt;
	if (((A[pos] - pos)&1) || (nxt & 1))
		puts("First");
	else
		puts("Second");
	
	return 0;
}