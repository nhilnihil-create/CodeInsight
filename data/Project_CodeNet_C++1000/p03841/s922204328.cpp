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

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 503;

int n;
int a[N];
int num[N];
int id[N*N];

bool cmp(int x,int y){return a[x]<a[y];}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)num[i]=i,id[a[i]]=i;
	sort(num+1,num+1+n,cmp);
	fo(i,1,n){
		int cnt=num[i]-1;
		fo(j,1,a[num[i]])
		if (!id[j]&&cnt){
			id[j]=num[i];
			cnt--;
			if (!cnt)break;
		}
	}
	fd(i,n,1){
		int cnt=n-num[i];
		fd(j,n*n,a[num[i]])
		if (!id[j]&&cnt){
			id[j]=num[i];
			cnt--;
			if (!cnt)break;
		}
	}
	bool ans=1;
	fo(i,1,n*n)if (!id[i])ans=0;
	if (ans){
		printf("Yes\n");
		fo(i,1,n*n)printf("%d%c",id[i],i<n*n?' ':'\n');
	}
	else printf("No\n");
	return 0;
}