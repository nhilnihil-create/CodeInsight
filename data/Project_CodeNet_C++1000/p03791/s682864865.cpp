#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define P 1000000007
#define N 100010
int n, a[N], b[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	int S = 1;
	for (int i = 0; i < n; i ++) {
		// first i-(a[i]+1)/2 are in first i+1
		b[i] = max(i-(a[i]-1)/2, 0);
	}
	for (int i = 1; i < n; i ++)
		b[i] = max(b[i], b[i-1]);
	for (int i = n-1; i >= 1; i --)
		S = (ll)S*(n-b[i-1]-(n-i-1))%P;
	printf ("%d\n", S);
	return 0;
}