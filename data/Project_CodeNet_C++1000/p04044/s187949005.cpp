#include <bits/stdc++.h>

#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;

const int N = 1e5 + 12;
const ll mod = 1e9 + 7;

int n, m;
string s[N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> s[i];
	sort(s + 1, s + n + 1);
	for(int i = 1;i <= n;i++)
		cout << s[i];
}
