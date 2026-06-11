#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
int n,ans[251000];
pair<int,int> e[510];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&e[i].first); e[i].second=i;
		ans[e[i].first]=i;
	}
	sort(e+1,e+n+1);
	int l=1,r=n*n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<e[i].second;j++){
			while (ans[l]) l++;
			if (l>=e[i].first){
				puts("No");
				return 0;
			}
			ans[l++]=e[i].second;
		}
	for (int i=n;i>=1;i--)
		for (int j=e[i].second+1;j<=n;j++){
			while (ans[r]) r--;
			if (r<=e[i].first){
				puts("No");
				return 0;
			}
			ans[r--]=e[i].second;
		}
	puts("Yes");
	for (int i=1;i<n*n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n*n]);
	return 0;
}
