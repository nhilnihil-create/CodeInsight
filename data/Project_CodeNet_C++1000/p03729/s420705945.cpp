#include <bits/stdc++.h>

using namespace std;

#define intt long long 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;

int n;
int a[N];

int main() {

	FAST;

	string a, b, c;
	cin >> a >> b >> c;
	int l1 = a.length();
	int l2 = b.length();
	if (a[l1 - 1] == b[0] && b[l2 - 1] == c[0]) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}