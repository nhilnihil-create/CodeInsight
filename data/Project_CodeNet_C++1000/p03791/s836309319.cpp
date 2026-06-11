#include<cstdio>
#include<algorithm>
#define mo 1000000007
using namespace std;
int n,ans,now;
int a[100005];
inline int read(){
    int ret=0;char c=getchar();
    while((c>'9')||(c<'0'))c=getchar();
    while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
    return ret;
}
int main(){
	n=read();ans=1;
	for(int i=1;i<=n;i++)a[i]=read();
	a[0]=-1;
	now=n;
	for(int i=1;i<=n;i++){
		a[i]=min(a[i],a[i-1]+2);
		if(a[i]-a[i-1]==1)ans=1LL*ans*(i+now-n)%mo,now--,a[i]--;
	}
	for(int i=now;i>1;i--)ans=1LL*ans*i%mo;
	printf("%d",ans);
}