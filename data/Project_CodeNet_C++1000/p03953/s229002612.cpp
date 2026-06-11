#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100010;
int a[maxn],c[maxn],b[maxn],A[maxn],ans[maxn];
int AA[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&AA[i]);
/**/	if(i!=1)a[i]=AA[i]-AA[i-1];
		else a[i]=AA[i];
		c[i]=i;
	}
	int m;LL k;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;++i){
		int x;
		scanf("%d",&x);
		swap(c[x],c[x+1]);
	}
//	cout<<a[3]<<endl;
	for(int i=1;i<=n;++i){
		if(!b[i]){
			int cnt=0;
			for(int j=i;!b[j];j=c[j]){
	//			cout<<j<<endl;
				b[j]=1;
				A[++cnt]=j;
			}
			for(int j=1;j<=cnt;++j){
				ans[A[j]]=a[A[((LL)(j+k-1))%cnt+1]];
		//		cout<<ans[A[j]]<<endl;
//				cout<<A[(j+k-1)%cnt+1]<<endl;
			}
		}
	}
	LL sum=0;
	for(int i=1;i<=n;++i){
		//cout<<ans[i]<<endl;
		sum+=ans[i];
		printf("%lld.0\n",sum);
	}
	return 0;
}