#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 300005
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
const long long inf = 2e18;
int n,m;
pp a[maxn]; int ans[maxn];
bool cmp (pp x1, pp x2){
	return (x1.second-x1.first)<(x2.second-x2.first);
}
int fen[maxn];
void add (int pos,int val){
	for (int i=pos;i<=m;i+=(i&(-i))){
		fen[i]+=val;
	}
}
int sum (int pos){
	int val=0;
	for(int i=pos; i>0; i-=(i&(-i))){
		val+=fen[i];
	}
	return val;
}

main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen(".inp","r",stdin); freopen(".out","w",stdout);
	//freopen("inp.txt","r",stdin);
	cin>>n>>m; int i,j,k;
	for (i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1,a+n+1,cmp);
	int spec=n;
	j=1;
	for (i=1;i<=m;i++){
		while (j<=n&&a[j].second-a[j].first+1<i){
			//cout<<i<<" "<<j<<" "<<a[j].second-a[j].first+1<<'\n';
			spec--;
			add(a[j].first,1); 
			if (a[j].second<m){
				add(a[j].second+1,-1);
			}
			j++;
		}
		for (k=i;k<=m;k+=i){
			ans[i]+=sum(k);
		}
		ans[i]+=spec;
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<'\n';
}