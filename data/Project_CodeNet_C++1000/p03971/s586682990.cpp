#include <bits/stdc++.h>
using namespace std;
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int p = 0;
	int b_rank = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			if (p < (a + b))	{
				cout << "Yes\n";
				p++;
			}
			else	cout << "No\n";
			continue;
		}
		if (s[i] == 'b') {
			if (p < (a + b) && b_rank <= b) {
				cout << "Yes\n";
				p++;
				b_rank++;
			}
			else	cout << "No\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}