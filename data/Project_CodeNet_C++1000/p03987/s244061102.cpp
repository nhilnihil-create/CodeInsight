#include<bits/stdc++.h>
using namespace std;
int n;
long long read(){
    long long x=0,y=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*y;
}
long long a[2000010];
long long st[2000010];
long long l[2000010],r[2000010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    a[i]=read();
	int top=0;
	for(int i=1;i<=n;i++) l[i]=0,r[i]=n+1;
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]>=a[i]) r[st[top--]]=i;
		l[i]=st[top];
		st[++top]=i;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	    ans+=(long long)((r[i]-i)*(i-l[i])*a[i]);
	printf("%lld",ans);
	return 0;
}