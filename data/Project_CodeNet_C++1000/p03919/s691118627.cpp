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
#include<deque>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

int main()
{
	int h,w;
	int a,b;
	cin >> h >> w;
	REP(i,h)
	{
		REP(j,w)
		{
			string str;cin >> str;
			if(str == "snuke"){a=i;b=j;}
		}
	}
	
	cout << (char)('A'+b) << a+1 << endl;
	
	return 0;
}