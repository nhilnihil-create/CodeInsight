#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i) = 0; (i) <= (n); (i)++)
using namespace std;

int H, W, d;

char ch[2][2] = { {'R', 'Y'}, {'G', 'B'} };

signed main()
{
	cin >> H >> W >> d;
	REP(y, H)
	{
		REP(x, W)
		{
			int xx = (x + y) % (d * 2);
			int yy = (x - y) % (d * 2);
			if (xx < 0) xx = d * 2 + xx;
			if (yy < 0) yy = d * 2 + yy;
			int a = abs(xx) / d;
			int b = abs(yy) / d;
			cout << ch[a][b];
		}
		cout << endl;
	}
}