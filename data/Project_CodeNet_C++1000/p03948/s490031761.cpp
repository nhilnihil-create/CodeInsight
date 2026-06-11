#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,t;
	cin>>n>>t;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	ll mini=INF,buf=0,c=0;
	REP(i,n) {
		mini=min(mini,a[i]);
		if(a[i]-mini>buf) {
			buf=a[i]-mini;
			c=1;
		} else if(a[i]-mini==buf) {
			++c;
		}
	}
	cout<<c<<endl;
}
