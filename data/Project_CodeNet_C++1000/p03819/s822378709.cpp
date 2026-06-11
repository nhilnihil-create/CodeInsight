#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n,a[101000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int L,R,l,r;
		scanf("%d%d",&L,&R);L--;
		for(l=1;l<=L;l=r+1){
			r=min(L/(L/l),R/(R/l));
			if(L/l!=R/l)a[l]++,a[r+1]--;
		}
		a[l]++;a[R+1]--;
	}
	for(int i=1;i<=m;i++){
		a[i]+=a[i-1];
		printf("%d\n",a[i]);
	}
}