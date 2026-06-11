#include<cstdio>
int n,a[100005],cur;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
const char*s[]={"First","Second"};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(;;cur^=1){
		int c=0,d=0;
		bool b=0;
		for(int i=1;i<=n;++i)c+=!(a[i]&1),b|=a[i]==1,d=gcd(d,a[i]^(a[i]&1));
		if(b)return puts(s[c&1^!cur]),0;
		if(c&1)return puts(s[cur]),0;
		if(c!=n-1)return puts(s[!cur]),0;
		for(int i=1;i<=n;++i)a[i]/=d;
	}
}