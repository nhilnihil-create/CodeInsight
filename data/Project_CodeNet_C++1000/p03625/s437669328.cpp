# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define end(x) prev(x.end());
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define mset multiset
# define umap unordered_map
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
# define lr(i,l,r) for(int i=l;(l>r?i>=r:i<=r);(l>r?--i:++i))

using namespace std;

template<class T> void umin(T &a, T b) { a = min(a, b); }
template<class T> void umax(T &a, T b) { a = max(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+5;

int dp[N],a[105];

void solve(){
	ll n;
	cin>>n;
	map<ll,ll>m;
	pqueue<ll>q;
	ll ans=1;
	forn(i,n){
		ll x;
		cin>>x;
		m[x]++;
		if(m[x]==2 || m[x]==4){
			q.push(x);
		}
	}
	if(sz(q)>1){
		ans*=q.top();
		q.pop();
		ans*=q.top();
		cout<<ans;
	}
	else cout<<0;

}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}
 

