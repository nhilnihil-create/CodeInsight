#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int pre1[N], pre2[N];
int sa[N], sb[N];

int main ()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	
	for (int i = 0; i < n; i++) {
		sa[i+1] = s1[i];
	}
	for (int i = 0; i < m; i++) {
		sb[i+1] = s2[i];
	}
	
	for (int i = 1; i <= n; i++) 
	{
		if (sa[i] == 'A') {
			pre1[i] = pre1[i-1] + 1;
		} else {
			pre1[i] = pre1[i-1] + 2;
		}
	}
	for (int i = 1; i<= m; i++) 
	{
		if (sb[i] == 'A') {
			pre2[i] = pre2[i-1] + 1;
		} else {
			pre2[i] = pre2[i-1] + 2;
		}
	}
	
	int q;
	cin >> q;
	while (q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int sum1 = pre1[b]-pre1[a-1], sum2 = pre2[d]-pre2[c-1];
		cout << (sum1%3 == sum2%3 ? "YES\n" : "NO\n");
			continue;
	}
	return 0;
}
