/*
 * じょえチャンネル
 * 高評価・チャンネル登録よろしくおねがいします！
 * https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)
template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int a[7];
signed main(){
	rep(i,7)cin>>a[i];
	int ans=0;
	ans+=a[1];

	int p=a[0],q=a[3],r=a[4];
	int pp=p,qq=q,rr=r;

	int ans1=0,ans2=0;
	if(p&&q&&r){
		ans1+=3;p--;q--;r--;
		ans1+=p/2*2;
		ans1+=q/2*2+r/2*2;
	}
	ans2+=pp/2*2;
	ans2+=qq/2*2+rr/2*2;
	cout<<ans+max(ans1,ans2)<<endl;
}
