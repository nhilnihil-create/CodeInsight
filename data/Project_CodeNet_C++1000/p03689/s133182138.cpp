#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<stack>
#include<queue>
#include <iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cerr << v[i] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
	int W, H, w, h;
	cin >> H >> W >> h >> w;

	ll sum = 0;

	REP(i, H)
	{
		REP(j, W)
		{
			if ((i + 1) % h == 0 && (j + 1) % w == 0)
			{
				sum -= ((1000 * (h*w - 1)) + 1);
			}
			else
			{
				sum += 1000;
			}
		}
	}

	if (sum <= 0)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	REP(i, H)
	{
		REP(j, W)
		{
			if ((i + 1) % h == 0 && (j + 1) % w == 0)
			{
				cout << -((1000 * (h*w - 1)) + 1);
			}
			else
			{
				cout << 1000;
			}
			if (j != W - 1)cout << ' ';
		}
		cout << endl;
	}


	return 0;
}
