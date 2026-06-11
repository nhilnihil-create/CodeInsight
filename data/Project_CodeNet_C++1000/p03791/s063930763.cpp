#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fe(i,a,b) for(int i=be[a];i;i=b[i].ne)
using namespace std;
char rch;
void readd(int &x){
	while ((rch=getchar())<'0');
	x=rch-'0';
	while ((rch=getchar())>='0') x=x*10+rch-'0';
}
const int p=1e9+7;
int n,t,x;
long long ans;
int main(){
	ans=1;
	scanf("%d",&n);
	t=1;//!!!
	fo(i,1,n-1){
		scanf("%d",&x);
		if (x<2*t-1){
			ans=ans*t%p;
			continue;
		}
		t++;
	}
	//t++;
	fo(i,2,t) ans=ans*i%p;
	printf("%lld\n",ans);
	return 0;
}
