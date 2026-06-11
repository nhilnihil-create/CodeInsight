#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<vector> 

typedef long long ll;
using namespace std;

#define N 1123456 
int getint(){
	int f=1,x=0; char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define mod 1000000007ll
int n; 
int a[N];
ll fac[N];
int main(){
	n=getint();
	fac[0]=1; for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	int tot=0,mn=1; 
	ll ans=1; int m=n; 
	for(int i=1;i<=n;i++){
		int x=getint();
//		cout<<x<<"===="<<mn<<endl;
		if(x>=mn){
			++tot; mn+=2; 
		} else {
			++tot; ans=ans*tot%mod; 
//			cout<<tot<<endl; 
			tot--;
			m--; 
		}
	}
	ans=ans*fac[m]%mod;
	cout<<ans<<endl;
	return 0;
}