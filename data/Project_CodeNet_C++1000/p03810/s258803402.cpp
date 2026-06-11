#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int MX=100011;
int n,a[MX];
int cal(){
	bool hs1=false;
	for(int i=1;i<=n;i++)if(a[i]==1)hs1=true;
	if(hs1){
		int S=0;
		for(int i=1;i<=n;i++)S^=((a[i]-1)&1);
		return S;
	}
	int c[2]={0};
	for(int i=1;i<=n;i++)++c[a[i]&1];
	if(c[1]==1)return -1;
	return c[0]&1;
}
inline int gcd(int x,int y){if(x<y)swap(x,y);while(y)x%=y,swap(x,y);return x;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int r=-1,T=0;
	while(1){
		if(~(r=cal())){
			puts((r^T)?"First":"Second");
			break;
		}
		else{
			T^=1;
			for(int i=1;i<=n;i++)a[i]>>=1;
			int g=0;
			for(int i=1;i<=n;i++)g=gcd(g,a[i]);
			for(int i=1;i<=n;i++)a[i]/=g;
		}
	}
	return 0;
}
