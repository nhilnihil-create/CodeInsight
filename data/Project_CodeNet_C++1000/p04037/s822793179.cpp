#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int a[maxn];
int n; 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int c1, c2;
	for (int i = 1; i <= n; i++)
		if (a[i] >= n - i + 1) {
			int ns = n - i + 1;
			c1 = a[i] - ns + 1;
			c2 = 1;
			for (int j = i - 1; j >= 1; j--)
				if (a[j] >= ns) c2++;
			break;
		}
	if (c1 % 2 == 1 && c2 % 2 == 1) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}
