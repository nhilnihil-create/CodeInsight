#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int a[maxn], b[maxn], p[maxn], q[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> p[i], q[p[i]] = i;
	int mn = 0;
	for (int i = 1; i <= n; i++) {
		int ea = a[i - 1] + 1, eb = b[i - 1] - 1;
		if (ea + eb < q[i]) ea = q[i] - eb;
		else eb = q[i] - ea;
		a[i] = ea, b[i] = eb;
		mn = min(mn, b[i]);
	}
	for (int i = 1; i <= n; i++)
		b[i] += -mn + 1;
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);
	return 0;
}
