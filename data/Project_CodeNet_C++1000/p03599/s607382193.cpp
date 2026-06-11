#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	ll tmp;
	ll x, y;
	int a, b, c, d, e, f;
	cin >> a>> b>> c>> d>> e>>f;
	bool ch[31][3001] = {}; //water, suger
	ch[0][0] = true;
	REP(i, 31){
		REP(j, 3001){
			if(ch[i][j]){
				if(i+a <= 30) ch[i+a][j] = true;
				if(i+b <= 30) ch[i+b][j] = true;
				if(j+c <= 3000) ch[i][j+c] = true;
				if(j+d <= 3000) ch[i][j+d] = true;
			}
		}
	}
	double nd = -1;
	int sw, su;
	REP(i, 31){
		REP(j, 3001){
			if(ch[i][j] && i * 100 + j <= f && i * e >= j
			&& (double)(j*100)/(i * 100 + j) > nd){
				nd = (double)(j*100)/(i * 100 + j);
				sw = (i * 100 + j);
				su = j;
			}
		}
	}
	cout << sw << " " << su << endl;
}
