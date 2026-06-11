#include<iostream>
#include<cstdio>
#include<queue>
#define LL long long
#define maxn 100005
using namespace std;
LL L=0,R=1e9;
int n;
LL A,B;
LL a[maxn];

bool check(LL x){
	LL cnt=0;
	for(int i=1;i<=n;i++){
		LL k=a[i];
		if(k<=x*B)continue;
		cnt+=(k-x*B-1ll)/A+1ll;
	}
	if(cnt<=x)return 1;else return 0;
}

int main(){
	scanf("%d%lld%lld",&n,&A,&B);
	A-=B;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	R++;
	while(L+1<R){
		LL mid=L+R>>1;
		if(check(mid))R=mid;else L=mid;
	}
	printf("%lld\n",R);
}