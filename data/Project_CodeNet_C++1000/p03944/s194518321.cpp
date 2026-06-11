//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	int w, h, n;
	cin >> w >> h >> n;
	int xmi = 0, xma = w, ymi = 0, yma = h;
	int x, y, a;
	REP(i, n){
		cin >> x>>y >> a;
		if(a == 1) xmi = max(xmi, x);
		if(a == 2) xma = min(xma, x);
		if(a == 3) ymi = max(ymi, y);
		if(a == 4) yma = min(yma, y);
	}
	cout << max(0,yma-ymi)*max(0,xma-xmi) << endl;
}