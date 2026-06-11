#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100010;
struct node{
	int x,id;
}a1[N];
int n;
ll ans[N];
inline int read(){
	int x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
bool cmp(node i,node j){
	if(i.x!=j.x)return i.x>j.x;
	return i.id>j.id;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){a1[i].x=read();a1[i].id=i;}
	sort(a1+1,a1+n+1,cmp);
	a1[n+1].x=0;
	memset(ans,0,sizeof ans);
	for(int mn=n+1,i=1;i<=n+1;i++){
		if(a1[i].x!=a1[i-1].x)ans[mn]+=1ll*(i-1)*(a1[i-1].x-a1[i].x);
		mn=min(mn,a1[i].id);
	}
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
	return 0;
}