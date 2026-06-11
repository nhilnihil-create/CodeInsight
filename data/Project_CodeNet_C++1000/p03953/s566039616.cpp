#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

LL get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		LL s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	LL s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e+5+5;

int n,m;
LL d[N],a1;
int id[N],num[N];
LL k;
bool vis[N];
int p,t[N];

int main(){
	n=get();
	a1=get();
	fo(i,1,n-1)d[i]=get();
	fd(i,n-1,2)d[i]-=d[i-1];
	d[1]-=a1;
	fo(i,1,n-1)id[i]=i;
	m=get();k=get();
	fo(i,1,m){
		int x=get();
		swap(id[x-1],id[x]);
	}
	fo(i,1,n-1)
	if (!vis[i]){
		vis[i]=1;
		t[p=1]=i;
		for(int x=id[i];x!=i;x=id[x])vis[t[++p]=x]=1;
		fo(j,1,p)num[t[j]]=t[(k+j-1)%p+1];
	}
	printf("%lld\n",a1);
	fo(i,1,n-1){
		a1+=d[num[i]];
		printf("%lld\n",a1);
	}
	return 0;
}