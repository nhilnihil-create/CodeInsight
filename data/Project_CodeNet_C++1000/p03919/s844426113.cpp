#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,long double> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

int h,w;
string s[30][30],t="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>h>>w;
	REP(i,h) REP(j,w) cin>>s[i][j];
	REP(i,h) {
		REP(j,w) {
			if(s[i][j]=="snuke") {
				cout<<t[j]<<i+1<<endl;
				return 0;
			}
		}
	}

	return 0;
}
