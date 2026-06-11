#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rp(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
using namespace std;
const ll maxn=5e5+5;
ll a[maxn],b[maxn],fa[maxn];
ll n,m,i,t,j,k,l,x,y,z,ans,mx,mi;
int main(){
	//freopen("data.in","r",stdin);
	scanf("%lld",&n);mi=n+1,mx=0;
	fo(i,1,n)scanf("%lld",&a[i]),mx=max(mx,a[i]),mi=min(mi,a[i]);
	if (mx==mi){
		if (mx<n-1 && 2*mx>n) printf("No");
		else printf("Yes");
	}else if (mx-mi>1) printf("No\n");
	else{
		t=0;
		fo(i,1,n) t+=(a[i]==mi);	
		n-=t;mx-=t;
		if (mx>0 && 2*mx<=n) printf("Yes");
		else printf("No");
	} 
}