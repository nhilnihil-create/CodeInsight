//#pragma GCC optimize(2)
#include<set>
#include<map>
#include<stack>
#include<ctime>
#include<cstdio>    
#include<queue>    
#include<cmath>    
#include<vector>    
#include<cstring>   
#include<climits>    
#include<iostream>   
#include<algorithm>
using namespace std;
#define LL long long
LL read(){
    LL f=1,x=0;char c=getchar();
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
    return f*x;
}
#define MAXN 5000
#define INF 10000000000000000ll
LL a[MAXN+5],mn[MAXN+5];
int main(){
	LL n=read(),x=read(),ans=INF;
	for(int i=1;i<=n;i++)
		a[i]=a[i+n]=read(),mn[i]=INF;
	for(int t=0;t<=n;t++){
		LL tmp=t*x;
		for(int i=1;i<=n;i++)
			mn[i]=min(mn[i],a[i+t]),tmp+=mn[i];
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}