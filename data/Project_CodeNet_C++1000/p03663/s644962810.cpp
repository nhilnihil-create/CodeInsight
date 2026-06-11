#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll in(){
    ll x=0;bool f=0; char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
ll ten[12],ans;
int pos;
char ch;
inline bool query(ll x){
	printf("? %lld\n",x);fflush(stdout);
	ch=getchar();while (ch!='Y'&&ch!='N') ch=getchar();
	return (ch=='Y');
}
int main()
{
	ten[0]=1ll;pos=-1;
	for (int i=1;i<=9;++i){
		ten[i]=ten[i-1]*10ll;
		if (!query(ten[i])) {pos=i;break;}
	}
	if (pos==-1){
		for (int i=1;i<=9;++i)
		if (query(ten[i]-1ll)) {pos=i-1;break;}
		if (pos==-1) pos=9;
		printf("! %lld",ten[pos]);fflush(stdout);
	}else{
		for (int i=1;i<=pos;++i){
			int l=(i==1),r=9,res=l;
			while (l<=r){
				int mid=(l+r)>>1;
				if (query((ans+1ll*mid*ten[pos-i])*10ll+ten[pos-i+1]-1ll)) res=mid,r=mid-1;
				else l=mid+1;
			}ans+=res*ten[pos-i];
		}printf("! %lld",ans);fflush(stdout);
	}return 0;
}