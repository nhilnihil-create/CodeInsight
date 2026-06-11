#include <bits/stdc++.h>
using  namespace std;

#define endl '\n'
#define ll long long
#define re register
#define pb(x) push_back(x)
#define ce(x) cout << x << '\n';

using db = long double;
using pll = pair < ll, ll >;

#define rep(i,x,n,inc) for(i=x ; i<n ; i+=inc)
#define repr(i,x,n,inc) for( i=x ; i>n ; i+=inc)
#define all(a)      (a).begin(),(a).end()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define hell 20007
const db pi = acos(-1);
const long long infl = LLONG_MAX;

#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Fill(s,v) memset(s,v,sizeof(s))
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl     //print with precision

#define tc(tt) \
    ll tt;    \
    cin >> tt; \
    for (ll _tt = 0; _tt < tt; _tt++) // testcase 

int32_t main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


ll t,i,x,j,y,z,k,n;
cin>>n;
ll p[n+1],a[n+1],b[n+1];
rep(i,1,n+1,1){
	cin>>x;
	p[x]=i;
}

rep(i,1,n+1,1){
	a[i]=i*hell;
	cout<<a[i]<<" ";
}
ce("")

rep(i,1,n+1,1){
	b[i]=(n-i)*hell+p[i];
	cout<<b[i]<<" ";
}

}
