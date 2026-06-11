#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));

int main(){
	ll n,t; cin >> n >> t; ll a[100010];
	REP(i,0,n) cin >> a[i];
	
	ll ma = 0, MA = 0, c = 0;
	RREP(i, n - 1, 0){
		ll pos = t / 2 * ma - t / 2 * a[i];
		
		if(MA < pos) MA = pos, c = 1;
		else if(MA == pos) c++;
		ma = max(ma, a[i]);
	}
	
	cout << c << endl;
	return 0;
}
