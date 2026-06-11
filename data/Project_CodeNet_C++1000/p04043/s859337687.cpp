#include <bits/stdc++.h>
#define ll uint64_t
#define vi vector <int>
#define vl vector <ll>
#define dl pair <ll, ll>
#define ii pair <ll, ll>
#define vii vector <ii>
#define graph vector <vector <int> >
#define inf 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int x, y, z;
	x = min(a, min(b, c));
	z = max(a, max(b, c));
	y = a + b + c - x - z;
	if (x == 5 && y == 5 && z == 7) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}