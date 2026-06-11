#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;

	int dx = tx - sx;
	int dy = ty - sy;
	cout << string(dy, 'U') << string(dx, 'R');
	cout << string(dy, 'D') << string(dx, 'L');
	cout << 'L' << string(dy+1, 'U') << string(dx+1, 'R') << 'D';
	cout << 'R' << string(dy+1, 'D') << string(dx+1, 'L') << 'U';
	cout << endl;
 	return 0;
}

