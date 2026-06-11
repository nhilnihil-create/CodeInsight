#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int ini[maxn], s[maxn];
int N, T, mx, ans;

int main()
{
	scanf("%d%d", &N, &T);
	for(int i = 1; i <= N; ++i) scanf("%d", &ini[i]);
	for(int i = N; i >= 1; --i) s[i] = max(s[i + 1], ini[i]);
	for(int i = 1; i < N; ++i) mx = max(mx, s[i + 1] -  ini[i]);
	for(int i = 1; i < N; ++i) if(s[i + 1] - ini[i] == mx) ans++;
	cout << ans;
	return 0;
}