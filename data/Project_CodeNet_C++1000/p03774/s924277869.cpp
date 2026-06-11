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
	int n, m;
	cin >> n >> m;
	int x, y;
	vector<int> a, b, c, d;
	REP(i, n){
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	REP(i, m){
		cin >> x >> y;
		c.push_back(x);
		d.push_back(y);
	}
	vector<int> an(n);
	REP(i, n){
		tmp = INTINF;
		REP(j, m){
			if(tmp > abs(a[i]- c[j]) + abs(b[i]-d[j])){
				tmp = abs(a[i]- c[j]) + abs(b[i]-d[j]);
				an[i] = j + 1;
			}
		}
	}
	REP(i,n) cout << an[i] << endl;
}