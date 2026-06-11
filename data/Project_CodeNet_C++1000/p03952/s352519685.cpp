//Code by Enderturtle
#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define repe(i,a) for(register int i=head[a];i;i=e[i].nxt)
#define il inline
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;
il void filejudge(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
il int read(){
	int x=0;bool f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=0;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return f?x:-x;
}
/*----- head end -----*/
int n,x,now=1;
int main(){
	n=read();x=read();
	if(x==1 || x==(2*n-1)) puts("No");
	else{
		puts("Yes");
		rep(i,1,n-2){
			while(now==x || now==x-1 || now==x+1) ++now;
			printf("%d\n",now);
			++now;
		}
		printf("%d\n%d\n%d\n",x-1,x,x+1);
		rep(i,1,n-2){
			while(now==x || now==x-1 || now==x+1) ++now;
			printf("%d\n",now);
			++now;			
		}
	}
	return 0;
}