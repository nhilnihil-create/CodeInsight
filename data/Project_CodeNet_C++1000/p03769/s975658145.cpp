#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int l, r, a[210], now;
ll m;
int main(){
	scanf("%lld", &m); m++; l=0; r=201; now=0;
	while(m>=2){
		if(m&1){now++; a[++l]=now; m--;}
		now++; a[--r]=now; m>>=1;
	}
	printf("%d\n", now<<1);
	for(int i=1; i<=l; i++)printf("%d ", a[i]);
	for(int i=r; i<=200; i++)printf("%d ", a[i]);
	for(int i=now; i>=2; i--)printf("%d ", i); printf("1");
	return 0;
}