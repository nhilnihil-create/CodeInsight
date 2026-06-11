# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define mset multiset
# define umap unordered_map
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
# define lr(i,l,r) for(int i=l;(l>r?i>=r:i<=r);(l>r?--i:++i))

using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int dx[]={1,0,-1,0,-1,-1,1,1},dy[]={0,1,0,-1,-1,1,-1,1}; 
const int mod = 1e9+7;
const ll N = 2e5+5;


void solve(){
	string s;
	cin>>s;
	int n=sz(s);
	vector<int>dp(n+1);
	dp[0]=1;
	for(int i=0;i<n;++i){
		if(!dp[i])continue;
		if(i+5<=n && s.substr(i,5)=="dream")dp[i+5]=1;
		if(i+7<=n && s.substr(i,7)=="dreamer")dp[i+7]=1;
		if(i+5<=n && s.substr(i,5)=="erase")dp[i+5]=1;
		if(i+6<=n && s.substr(i,6)=="eraser")dp[i+6]=1;
	}
	cout<<(dp[n]?"YES":"NO");
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}