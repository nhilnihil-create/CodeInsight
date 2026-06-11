#include<cstdio>
#include<algorithm>
using namespace std;

const int MOD=1e9+7;
int n,a=0,d=0,mmh=1;
int main(){
	register int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		d=max(d,i-1-(a+1)/2);
		mmh=1LL*mmh*(i-d)%MOD;
		scanf("%d",&a);
	}
	printf("%d\n",mmh);
}