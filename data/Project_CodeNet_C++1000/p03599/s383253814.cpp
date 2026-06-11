#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int a, b, c, d, e, f;
int xx, yy;

bool check(int x, int y)
{
	bool flag = false;
	for (int i = 0; i * 100 * a <= x; i ++ )
		for (int j = 0; j * 100 * b <= x - i * 100; j ++ )
			if (!flag && i * a * 100 + j * b * 100 == x)
			{
				flag = true;
				break;
			}
	if (!flag) return false;
	
	flag = false;
	for (int i = 0; i * c <= y; i ++ )
		for (int j = 0; j * d <= y - i; j ++ )
			if (!flag && i * c + j * d == y)
			{
				flag = true;
				break;
			}
	return flag;
}

int main()
{
	cin >> a >> b >> c >> d >> e >> f;
	
	double res = -1;
	for (int x = 0; x <= f / 100; x ++ )
		for (int y = 0; y <= x * e; y ++ )
			if (100 * x + y <= f && check(100 * x, y))
				if (res < (double)y / (100 * x + y))
				{
					res = (double)y / (100 * x + y);
					xx = x, yy = y;
				}
	
	cout << xx * 100 + yy << ' ' << yy << endl;
    return 0;
}