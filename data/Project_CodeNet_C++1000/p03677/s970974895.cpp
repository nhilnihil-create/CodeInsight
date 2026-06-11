#include<cstdio>
#include<algorithm>
#define ll long long
const int N=1e5+5;
using namespace std;
int n,m,i,x,y,fx[N];
ll f[N],ans;
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void add_f(int l,int r,int k){f[l]+=k;f[r+1]-=k;}
void add_fx(int l,int r,int k){fx[l]+=k;fx[r+1]-=k;}
int main(){
	n=read();m=read();y=read();
	for (n--;n--;){
		x=y;y=read();
		if (x<=y){
			add_f(1,x,y-x);
			add_f(x+1,y,y+1);add_fx(x+1,y,-1);
			add_f(y+1,m,y-x);
		}
		else{
			add_f(1,y,y+1);add_fx(1,y,-1);
			add_f(y+1,x,m-x+y);
			add_f(x+1,m,m+y+1);add_fx(x+1,m,-1);
		}
	}
	for (ans=1e18,i=1;i<=m;i++){
		f[i]+=f[i-1];fx[i]+=fx[i-1];
		ans=min(ans,f[i]+(ll)i*fx[i]);
	}
	printf("%lld",ans);
}