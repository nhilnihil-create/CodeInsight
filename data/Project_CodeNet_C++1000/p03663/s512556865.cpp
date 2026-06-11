#include<cstdio>
#include<cctype>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mid (l+r>>1)
#define reg register
typedef long long ll;
template<typename T>inline T read(){
    reg T x=0;reg short f=1;reg char c=getchar();
    for(;!isdigit(c);f=c=='-'?-1:1,c=getchar());
    for(;isdigit(c);x=x*10+(c^48),c=getchar());
    return x*f;
}
char ch[10];
bool f1[11],f2[11];
inline bool query(ll k){
	printf("? %lld\n",k);fflush(stdout);
	scanf("%s",ch);return ch[0]=='Y';
}
inline void search(ll l,ll r){
	reg int res=0;
	while(l<=r)
		if(query(1ll*mid*10))res=mid,r=mid-1;
		else l=mid+1;
	printf("! %d\n",res);
}
int main(){
	reg int f=1;
	for(reg int i=1,x=10;i<=9;i++,x*=10){
		f1[i]=query(x);f2[i]=query(x-1);f&=f1[i];
	}
	if(f){
		reg int l=1,r=1e9;
		for(reg int i=1,x=10;i<=9;i++,x*=10){
			if(!f2[i])l=x;
			else r=min(r,x-1);
		}
		search(l,r);
	}
	else{
		reg int last=9,res=1e9;
		while(last&&!f1[last])last--,res/=10;
		search(res,1ll*res*10-1);
	}
    return 0;
}