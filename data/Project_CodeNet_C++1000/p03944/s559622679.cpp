#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;

int lx[Max][2], ly[Max][2];

int main()
{
	int x, y, n;
	cin >> x >> y >> n;
	while(n--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 1)lx[a][0] = 1;
		if (c == 2)lx[a][1] = 1;
		if (c == 3)ly[b][0] = 1;
		if (c == 4)ly[b][1] = 1;
	}
	int trx = x, tlx = 0, ty = y, tly = 0;
	for (int i = 1; i <= max(x,y); i++)
	{
		if (lx[i][0])tlx = max(tlx, i);
		if (lx[i][1])trx = min(trx, i);
		if (ly[i][0])tly = max(tly, i);
		if (ly[i][1])ty = min(ty, i);
	}
	if (tlx >= trx || tly >= ty)cout << 0 << endl;
	else cout << (trx - tlx) * (ty - tly) << endl;
}