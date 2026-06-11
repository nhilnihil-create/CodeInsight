#include <bits/stdc++.h>
#define intl long long
using namespace std;

intl ans = 1;
intl res;
int A[1010000];
int n;

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&A[i]);
	for (int i = 2; i <= n; i++) A[i] = min(A[i], A[i - 1] + 2);
	res = 1;
	for (int i = 1; i <= n; i++) {
		ans *= min((res + i - 1) / 2LL + 1LL, (intl) i);
		ans %= 1000000007LL;
		res += ((A[i] - A[i - 1] - 1));	
	}
	cout << ans << endl;
}