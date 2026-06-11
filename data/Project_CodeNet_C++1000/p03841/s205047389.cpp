#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=500+10;
bool bz[maxn];
int cnt[maxn];
int x[maxn],b[maxn],a[maxn*maxn];
int i,j,k,l,t,n,m,tot,top;
bool czy;
int main(){
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%d",&t);
		a[x[i]=t]=i;
	}
	fo(i,1,n*n) 
		if (a[i]) b[++top]=a[i];
	fo(i,1,n) cnt[i]=i-1;
	fo(i,1,n*n)
		if (!a[i]){
			fo(j,1,n)
				if (cnt[b[j]]){
					a[i]=b[j];
					cnt[b[j]]--;
					break;
				}
		}
	fo(i,1,n) cnt[i]=n-i;
	fd(i,n*n,1)
		if (!a[i]){
			fd(j,n,1)
				if (cnt[b[j]]){
					a[i]=b[j];
					cnt[b[j]]--;
					break;
				}
		}
	czy=1;
	fo(i,1,n){
		tot=0;
		fo(j,1,n*n)
			if (a[j]==i){
				tot++;
				if (tot==i) break;
			}
		if (j!=x[i]){
			czy=0;
			break;
		}
	}
	if (!czy) printf("No\n");
	else{
		printf("Yes\n");
		fo(i,1,n*n) printf("%d ",a[i]);
	}
}