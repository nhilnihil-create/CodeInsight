#include<cstdio>
#include<algorithm>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
const int N=1e5+11;
int n,ans;
int a[N];
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)
		scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)
		if(i+1>a[i+1]){
			for(int j=i+1;a[j]==i;++j)
				ans^=1;
			ans|=(a[i]-i)&1;
			break;
		}
	puts(ans?"First":"Second");
	return 0;
}