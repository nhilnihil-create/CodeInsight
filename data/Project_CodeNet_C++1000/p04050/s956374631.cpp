#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int a[100000+10],b[100000+10];
int i,j,k,l,t,n,m,cnt;
int main(){
	//freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m){
		scanf("%d",&a[i]);
		if (a[i]%2==1){
			if (cnt==0) j=i;
			else k=i;
			cnt++;
		}
	}
	if (cnt>2){
		printf("Impossible\n");
		return 0;
	}
	if (cnt) swap(a[1],a[j]);
	if (cnt>1) swap(a[m],a[k]);
	if (m==1){
		if (a[1]==1){
			printf("1\n1\n1\n");
			return 0;
		}
		printf("%d\n",a[1]);
		printf("2\n");
		printf("%d 1\n",a[1]-1);
		return 0;
	}
	fo(i,1,m) printf("%d ",a[i]);
	printf("\n");
	if (a[m]==1) printf("%d\n",m-1);else printf("%d\n",m);
	printf("%d ",a[1]+1);
	fo(i,2,m-1) printf("%d ",a[i]);
	if (a[m]>1) printf("%d\n",a[m]-1);
}