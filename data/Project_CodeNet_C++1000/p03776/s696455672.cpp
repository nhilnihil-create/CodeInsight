#include "cstdio"
#include "algorithm"
using namespace std;
long long s[55],sss,maxx,i,a,b,n,ss[55][55],ss1,ss2,j;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	scanf("%lld",&n);scanf("%lld%lld",&a,&b);ss[0][0]=1;
	for(i=1;i<=50;i++){
		ss[i][0]=1;
		for(j=1;j<=i;j++)ss[i][j]=ss[i-1][j]+ss[i-1][j-1];
	}
	for(i=1;i<=n;i++)scanf("%lld",&s[i]);
	sort(s+1,s+1+n,cmp);
	for(i=1;i<=a;i++)sss+=s[i];
	for(i=1;i<=n;i++){
	    if(s[i]==s[a])ss1++;if(s[i]==s[a]&&i<=a)ss2++;
	}
	if(s[1]==s[a])
	for(i=a;i<=b;i++)maxx+=ss[ss1][i];
	else maxx=ss[ss1][ss2];
	printf("%lf %lld\n",sss*1.0/a,maxx);
}