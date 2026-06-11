#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int cache[N][N];

int dp(int x, int y)
{
	int &ans = cache[x][y];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i = 1; i * 2 <= x; i++)
		ans |= !(dp(x - 2 * i, y + i));
	for(int i = 1; i * 2 <= y; i++)
		ans |= !(dp(x + i, y - 2 * i));
	return ans;
}

int32_t main()
{
	IOS;
	int x, y;
	cin >> x >> y;
	if(abs(x -  y) >= 2)
		cout << "Alice" << endl;
	else
		cout << "Brown" << endl;
	return 0;
}