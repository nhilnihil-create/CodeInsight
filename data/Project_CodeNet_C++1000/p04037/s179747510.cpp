#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
#define rep(i,j,k) for(i=j;i<=k;++i)
int n,i,j,k,top,up,right;
int a[N],x[N<<1],y[N<<1];
void read(int &p){
	p=0; char x=getchar();
	while(x<'0' || x>'9') x=getchar();
	while(x>='0'&&x<='9'){p=p*10+x-'0'; x=getchar();}
}
bool cmp(int a,int b){ return a>b; }
int main(){
	read(n);
	rep(i,1,n) read(a[i]);
	sort(a+1,a+1+n,cmp);
	top++; x[1]=0; y[1]=a[1];
	rep(i,1,n)
	if(a[i]!=a[i+1]){
		top++; x[top]=i; y[top]=a[i];
		top++; x[top]=i; y[top]=a[i+1];
	}
	rep(i,1,top)
	if(y[i]-x[i]==0){
		if(y[i]==a[x[i]]){
			puts("Second");
		}else{
			up=((y[i-1]-y[i])&1)?1:0;
			right=((x[i+1]-x[i])&1)?1:0;
			if(up || right) puts("First");
			else puts("Second");
		}
		break ;
	}else
	if(y[i]-x[i]<0){
		if(a[x[i-1]]==y[i-1]){
			if((y[i-1]-x[i-1])&1) puts("First");
			else puts("Second");
		}else{
			if((x[i]-y[i-1])&1) puts("First");
			else puts("Second");
		}
		break ;
	}
	return 0;
}