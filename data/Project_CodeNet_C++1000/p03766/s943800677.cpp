#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<queue>
#include<set>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int p=1e9+7;
int n;
long long f[1200000],m,s[1200000];
int main(){
	scanf("%d",&n);
	m=n-1;m=m*m%p;
	f[n]=n;
	/*fd(i,n-1,1){
		f[i]=(f[i+1]+m)%p;
		fo(j,2,n) if (i+j+1<=n) f[i]+=f[i+j+1];else f[i]++;
		f[i]%=p;
		//printf("%d:%lld\n",i,f[i]);
	}*/
	s[n]=n;
	fd(i,n-1,1){
		f[i]=(f[i+1]+m)%p;
		if (i<n-1) f[i]=(f[i]+i+1)%p;else f[i]=(f[i]+n-1)%p;//!!!!!!!!!!
		if (i+3<=n) f[i]=(f[i]+s[i+3])%p;//!!!!!!!!!!!!!  f[i+3]..f[i+n+1]  f[n+1]..f[i+n+1]=1
		s[i]=(s[i+1]+f[i])%p;
		//printf("%d:%lld\n",i,f[i]);
	}
	printf("%lld\n",f[1]);
	return 0;
}