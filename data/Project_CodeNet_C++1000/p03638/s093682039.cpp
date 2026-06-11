// セグフォ一生取れなかったので解答AC
// ヘビのライブラリは作った方がいい
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int h,w,n,a[10005];
vector<P>vec;
void go(int p,int q,int r,int s){
	for(int i=q;i<=s;i++) vec.pb(mp(p,i));
	for(int i=p+1;i<=r;i++) vec.pb(mp(i,s));
	for(int i=s-1;i>=q;i--) vec.pb(mp(r,i));
	for(int i=r-1;i>p;i--) vec.pb(mp(i,q));
	if(p+1<=r-1&&q+1<=s-1) go(p+1,q+1,r-1,s-1);
}
int ans[105][105];
int main(){
	cin >> h >> w >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	go(1,1,h,w);
	int s = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			ans[vec[s].fi][vec[s].sc] = i;
			s++;
		}
	}
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) printf("%d%c",ans[i][j],j==w?'\n':' ');
}
