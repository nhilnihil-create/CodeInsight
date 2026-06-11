#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N,M,cnt[100005];
bool red[100005];
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>N>>M;
	fill(cnt,cnt+N,1);
	red[0]=true;
	while(M--){
		int x,y;cin>>x>>y;x--;y--;
		if(red[x])red[y]=true;
		if(cnt[x]==1)red[x]=false;
		cnt[x]--;cnt[y]++;
	}
	int ans=0;
	rep(i,N)ans+=red[i];
	cout<<ans<<endl;
}
