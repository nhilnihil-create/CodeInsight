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
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;

//-----------------------------------------------------------------------------

int n,k;
ll a[5000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>k;
	REP(i,n) {
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	ll sum=0;
	int ans=n;
	REP(i,n) {
		if(sum+a[i]<k) sum+=a[i];
		else ans=n-i-1;
	}
	cout<<ans<<endl;

	return 0;
}
