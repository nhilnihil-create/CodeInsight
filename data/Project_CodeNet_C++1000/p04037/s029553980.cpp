// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1 << 29;
const int maxn=1e5+5;

int n;
int a[maxn];

int cmp(int a,int b){return a>b;}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	
	int t=1,sym;
	for(;t<=n;t++){
		if(a[t+1]<t+1){break;}
	}
	if((a[t]-t)%2==1){
		puts("First");
		return 0;
	}
	sym=0;
	for(int j=t+1;j<=n;j++){
		if(a[j]==t)sym^=1;
		else break;
	}
	if(sym)puts("First");
	else puts("Second");

	return 0;
}
