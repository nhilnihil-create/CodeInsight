#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<functional>
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

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

ll n,t,ma,mi = 10000000000,cou = 1,sa;

int main()
{
	cin >> n >> t;
	
	REP(i,n)
	{
		ll a;cin>> a;
		if(a - mi > sa)
		{
			sa = a - mi;
			cou = 1;
		}
		else if(a - mi == sa)cou++;
		
		mi = min(mi,a);
		ma = max(ma,a);
	}
	
	cout << cou << endl;
	
	return 0;
}