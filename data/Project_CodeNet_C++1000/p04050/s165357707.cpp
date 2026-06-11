#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
#define rep(i,j,k) for(i=j;i<=k;++i)
int ans,odd,n,m,i,j,k;
int a[N],b[N],pos[3];
void read(int &p){
	p=0; char x=getchar();
	while(x<'0' || x>'9') x=getchar();
	while(x>='0'&&x<='9'){p=p*10+x-'0'; x=getchar();}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n); read(m);
	rep(i,1,m){
		read(a[i]);
		if(a[i]&1){
			odd++;
			if(odd>2) {puts("Impossible"); return 0;}
			pos[odd]=i;
		}
	}
	if(pos[1]) swap(a[1],a[pos[1]]);
	if(pos[2]) swap(a[m],a[pos[2]]);
	if(odd==0){
		b[ans=1]=1;
		rep(i,1,m) ans++,b[ans]=a[i];
		b[ans]--;
	}
	if(odd==1){
		rep(i,1,a[1]>>1) ans++,b[ans]=2;
		rep(i,2,m) ans++,b[ans]=a[i];
		ans++; b[ans]=1;
	}
	if(odd==2){
		rep(i,1,a[1]>>1) ans++,b[ans]=2;
		rep(i,2,m-1) ans++,b[ans]=a[i];
		ans++; b[ans]=2;
		rep(i,1,a[m]>>1) ans++,b[ans]=2;
	}
	rep(i,1,m) 
	if(i<m) printf("%d ",a[i]);
	else printf("%d\n",a[i]);
	printf("%d\n",ans);
	rep(i,1,ans)
	if(i<ans) printf("%d ",b[i]);
	else printf("%d\n",b[i]);
	return 0;
} 