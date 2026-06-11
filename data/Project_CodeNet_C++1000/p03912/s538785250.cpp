#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

/*--------Library Zone!--------*/

int n,m,x[114514];
int sum[114514];
int pa[114514];
int cnt[114514];
signed main(){
	cin>>n>>m;
	rep(i,n){
		cin>>x[i];
		sum[x[i]]++;
	}
	REP(i,100001){
		pa[i%m]+=sum[i]/2;
		cnt[i%m]+=sum[i];
	}
	int ans=0;
	rep(i,m/2+1){
		if(!i||i*2==m){
			ans+=cnt[i]/2;
		}else {
			if(cnt[i]<cnt[m-i]){
				int ma=min(pa[m-i],(cnt[m-i]-cnt[i])/2);
				ans+=ma;
				ans+=cnt[i];
			}else {
				int ma=min(pa[i],(cnt[i]-cnt[m-i])/2);
				ans+=ma;
				ans+=cnt[m-i];
			}
		}
	}
	cout<<ans<<endl;
}
