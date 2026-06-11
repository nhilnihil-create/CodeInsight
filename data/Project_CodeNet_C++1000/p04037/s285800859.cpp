#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
inline ll read(){
	ll res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){res=(res<<3)+(res<<1)+ch-'0';ch=getchar();}
	return res*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10|'0');
}
const int N=1e5+7;
int a[N],n,T;
signed main(){
//	freopen("t1.in","r",stdin);
//	freopen("t1.out","w",stdout);
//	T=read();
//	while(T--){
	n=read();
    for (int i=1; i<=n; ++i) a[i]=read();
    sort(a+1,a+n+1,greater<int>());
    for (int i=1; i<=n; ++i)
    if (i+1>a[i+1]){
    	int j=i+1,ans=0; 
		while (a[j]==i) ans++,j++;
		if (ans%2==1||(a[i]-i)%2==1) puts("First");
		else puts("Second");
		break;
    }
//	}
}	

