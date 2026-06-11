#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 100005
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
const long long inf = 2e18;
int n; pp a[maxn]; int ans[maxn];
main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen(".inp","r",stdin); freopen(".out","w",stdout);
	//freopen("inp.txt","r",stdin);
	cin>>n; int i,j,k;
	for (i=1;i<=n;i++){
		cin>>a[i].first; a[i].second=i;
	}
	sort(a+1,a+n+1);
	i=n; int cur=0,curmin=n+1;
	a[0].first=0;
	while (i>0){
		j=i; curmin=min(curmin,a[j].second);
		while (j>0&&a[j-1].first==a[j].first){
			j--; curmin=min(curmin,a[j].second);
		}
		int pos=curmin,val=a[j].first;
		cur=n+1-j;
		ans[pos]+=cur*(a[j].first-a[j-1].first);
		i=j-1;
	}
	for (i=1;i<=n;i++) cout<<ans[i]<<'\n';
}