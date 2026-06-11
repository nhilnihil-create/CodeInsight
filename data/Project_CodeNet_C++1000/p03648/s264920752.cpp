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
ll arr[51];
int main(){
	for(int i=0;i<51;i++){
		arr[i]=i;
	}
	ll n;
	cin>>n;
	ll c=0;
	c=n/50;
		cout<<"50"<<endl;
		for(int i=0;i<50-n%50;i++){
			if(i!=0){
				cout<<' ';
			}
			cout<<arr[i]+c;
		}
		for(int i=50-n%50;i<50;i++){
			if(i!=0){
				cout<<' ';
			}
			cout<<arr[i]+1+c;
		}
}