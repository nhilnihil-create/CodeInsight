#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=100000;
int n,m,a[maxn+10],cnt; ll tot,ans,maxv;
vector<int> ins[maxn+10],del[maxn+10];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<n;++i){
		if(a[i]<=a[i+1]){
			if(a[i+1]==m) ++cnt,tot+=m-a[i]-1;
			ans+=a[i+1]-a[i];
		}else{
			if(a[i]!=m) ++cnt,tot+=m-a[i]-1;
			ans+=a[i+1]+m-a[i];
		}
		ins[a[i]==m?1:a[i]+1].push_back(i);
		del[a[i+1]==m?1:a[i+1]+1].push_back(i);
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<del[i].size();++j){
			int e=del[i][j];
			tot-=a[e]<=a[e+1]?a[e+1]-a[e]-1:m-a[e]+a[e+1]-1;
			--cnt;
		}
		tot+=cnt;
		for(int j=0;j<ins[i].size();++j) ++cnt;
		maxv=max(maxv,tot);
	}
	printf("%lld",ans-maxv);
}