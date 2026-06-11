#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF LLONG_MAX
#define eps LDBL_EPSILON
#define moder 1000000007
#define pie 3.141592653589793238462643383279
#define P std::pair<int,int>
#define prique priority_queue
using namespace std;
int n,ans[250010],used[510];
P x[510];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].first;
		x[i].second=i;
		ans[x[i].first]=i;
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n*n;i++){
		if(ans[i]){
			used[ans[i]]++;
			continue;
		}
		bool flag=false;
		for(int j=1;j<=n;j++){
			if(i<x[j].first&&used[x[j].second]+1<x[j].second){
				ans[i]=x[j].second;
				used[x[j].second]++;
				flag=true;
				break;
			}
		}
		if(flag)continue;
		for(int j=1;j<=n;j++){
			if(used[x[j].second]+1<=n){
				ans[i]=x[j].second;
				used[x[j].second]++;
				flag=true;
				break;
			}
		}
		if(!flag){
			puts("No");
			return 0;
		}
	}
	memset(used,0,sizeof(used));
	for(int i=1;i<=n*n;i++){
		used[ans[i]]++;
		for(int j=1;j<=n;j++){
			if(i==x[j].first&&used[x[j].second]!=x[j].second){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++)cout<<ans[i]<<endl;
	return 0;
}