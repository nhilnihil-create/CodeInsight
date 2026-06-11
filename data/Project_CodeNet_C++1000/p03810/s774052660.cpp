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

const int N = 100005;

int n;
int a[N];

int gcd(int x,int y){
	if (!y)return x;
	return gcd(y,x%y);
}

bool solve(){
	sort(a+1,a+1+n);
	int cnt0=0,cnt1=0;
	fo(i,1,n)
	if (a[i]&1)cnt1++;else cnt0++;
	if (cnt0%2==1)return 1;
	else{
		if (cnt1>1||(cnt1==1&&a[1]==1))return 0;
		fo(i,1,n)if (a[i]&1){a[i]--;break;}
		int g=a[1];
		fo(i,1,n)g=gcd(g,a[i]);
		fo(i,1,n)a[i]/=g;
		return solve()^1;
	}
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	if (solve())printf("First\n");
	else printf("Second\n");
	return 0;
}