#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
ll f[maxn],s[maxn],t[maxn],mx=0;
int a[maxn],n;
char c[10];
int main(){
	scanf("%d",&n);
	for(int i=1,fu;i<=n;++i){
		if(i>1){
			scanf("%s",c);
			fu=(c[0]=='-'?-1:1);
		} else fu=1;
		scanf("%d",&a[i]);
		a[i]*=fu;
	}
	for(int i=n,lst=0;i>=1;--i){
		s[i]=s[i+1]+a[i];
		t[i]=t[i+1]+abs(a[i]);
		f[i]=-1ll<<60;
		if(a[i]<0){
			if(lst)f[i]=-(s[i+1]-s[lst])+t[lst]+a[i];
			lst=i;
		}
		f[i]=max(f[i],f[i+1]+a[i]);
	}
	printf("%lld",f[1]);
}