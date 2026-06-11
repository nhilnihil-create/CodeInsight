#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
int a[1010101],n;
inline void doit(){
	int G=a[1];
	for (int i=2;i<=n;i++) G=__gcd(G,a[i]);
	for (int i=1;i<=n;i++) a[i]/=G;
}
signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (bool cur=0;;cur^=1){
		int flag1=0,cnt_e=0,cnt_o=0,pos1=0;
		for (int i=1;i<=n;i++){
			cnt_e+=!(a[i]%2),cnt_o+=a[i]%2,flag1|=(a[i]==1);
			if (a[i]&1) pos1=i;
		}
		if (flag1){
			puts((cnt_e&1)^cur?"First":"Second");return 0;
		}
		if (cnt_e&1){
			puts(cur?"Second":"First");return 0;
		}else{
			if (cnt_o==1) a[pos1]--,doit();
			else{
				puts(cur?"First":"Second");return 0;
			}
		}
	}
    return 0;
}
