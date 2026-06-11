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
typedef pair<ll,int> P;
//typedef pair<int,P> PP;

//-----------------------------------------------------------------------------

int w,h;
ll ans;
vector<P> v;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>w>>h;
	int tmp;
	REP(i,w) {
		cin>>tmp;
		v.pb(P(tmp,0));
	}
	REP(i,h) {
		cin>>tmp;
		v.pb(P(tmp,1));
	}
	sort(v.begin(),v.end());
	h++,w++;
	for(auto u:v) {
		if(u.se==0) ans+=u.fi*h,w--;
		else ans+=u.fi*w,h--;
		//cout<<"u.fi="<<u.fi<<",u.se="<<u.se<<",ans="<<ans<<endl;
	}
	cout<<ans<<endl;

	return 0;
}
