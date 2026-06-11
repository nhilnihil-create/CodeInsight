#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100010];
int main(){
	int i,j,k,m,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0,tmp;
	for (i=1;i<n;i++){
		if (a[i]==i){
			ans++;
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
		}
	}
	for (i=n;i>1;i--){
		if (a[i]==i){
			ans++;
			tmp=a[i];
			a[i]=a[i-1];
			a[i-1]=tmp;
		}
	}
	printf("%d\n",ans);
	return 0;
}