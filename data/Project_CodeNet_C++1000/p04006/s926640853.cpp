#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define sortv(a); sort(a.begin(), a.end());
#define rev(a); reverse(a.begin(), a.end());
#define FOR(i,a,b) for (ll i = (ll)(a); i < (b); i++)
#define ROF(i,a,b) for (ll i = (ll)(b)-1; i >= (a); i--)
#define printarray(a) FOR(Q,0,(int)(a).size()) cout<<(a)[Q]<<" "; cout<<'\n';

ll MOD = 1000000007;
ll INF = 1LL << 60;

/*****************************************************************************/
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,x;cin>>n>>x;
	vec a(n);
	FOR(i,0,n) cin>>a[i];
	vec m(n,INF);
	ll out=INF,temp;
	FOR(i,0,n) {
		temp=i*x;
		FOR(j,0,n) {
			m[j]=min(m[j],a[(n+j-i)%n]);
			temp+=m[j];
		}
		out=min(out,temp);
	}
	cout<<out;
}