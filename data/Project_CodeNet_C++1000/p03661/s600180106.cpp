#include<iostream> 
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;

#define sf scanf
#define pf printf
#define pfn printf("\n");
#define pfk printf(" ");
#define pf0 printf("0");
#define pf1 printf("1");
#define ll long long
#define sfd(n) scanf("%d",&n);
#define sfdd(n,m) scanf("%d%d",&n,&m);
#define sfld(n) scanf("%lld",&n);
#define sfldd(n,m) scanf("%lld%lld",&n,&m);
#define sflf(n) scanf("%lf",&n);
#define sflff(n,m) scanf("%lf%lf",&n,&m);
#define sfc(n) scanf("%c",n);
#define sfcc(n,m) scanf("%c%c",n,m);
#define sfs(n) scanf("%s",n);
#define sfss(n,m) scanf("%s%s",n,m);
#define pfd(n) printf("%d",n);
#define pfld(n) printf("%lld",n);
#define pflf(n) printf("%lf",n);
#define pfc(n) printf("%c",n);
#define pfs(n) printf("%s",n);

#define csh(a,n) memset(a,n,sizeof(a));
ll arr[1000000];
int main(){
	ll n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	ll aaa=0;
	ll mini=1000000000000000000;
	for(int i=0;i<n-1;i++){	
		aaa+=arr[i];
		mini=min(mini,abs(sum-2*aaa));
	}
	cout<<mini<<endl;
}