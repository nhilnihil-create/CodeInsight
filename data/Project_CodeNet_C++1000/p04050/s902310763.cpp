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

const int N = 1000010;

int a[N],n;
int b[N],m;
int len;

int main(){
	len=get();n=get();
	fo(i,1,n)a[i]=get();
	fo(i,2,n-1)
		if (a[i]%2){
			if (a[n]%2)swap(a[i],a[1]);
			else swap(a[n],a[i]);
		}
	if (a[1]%2&&a[n]%2==0)swap(a[1],a[n]);
	int cnt=0;
	fo(i,1,n)cnt+=a[i]%2;
	if (cnt>2){
		printf("Impossible\n");
		return 0;
	}
	if (n==1){
		if (a[1]>1)printf("%d\n2\n1 %d\n",a[1],a[1]-1);
		else printf("1\n1\n1\n");
		return 0;
	}
	b[1]=a[1]+1;
	fo(i,2,n-1)b[i]=a[i];
	b[n]=a[n]-1;
	fo(i,1,n)printf("%d ",a[i]);putchar('\n');
	if (!b[n])n--;
	printf("%d\n",n);
	fo(i,1,n)printf("%d ",b[i]);putchar('\n');
	return 0;
}