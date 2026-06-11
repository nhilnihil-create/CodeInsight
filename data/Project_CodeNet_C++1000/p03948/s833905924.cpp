#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100010
int n,T,num,ans,a[N];
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int mn=a[1];
	for(int i=2;i<=n;++i){
		if(mn<a[i]) ans=max(ans,a[i]-mn);
		mn=min(mn,a[i]); 
	}
	mn=a[1];
	for(int i=2;i<=n;++i){
		if(a[i]-mn==ans) num++;
		mn=min(a[i],mn);
	}
	printf("%d\n",num);
	return 0;
}