#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int c[110000];
long long sum[210000];
long long sum2[210000];
long long tot[210000];
void add(int a,int b){
	sum2[a]++;
	sum2[b]--;
	sum[b+1]-=b-a;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",c+i);
		c[i]--;
	}
	long long val=0;
	for(int i=0;i<a-1;i++){
		val+=(c[i+1]-c[i]+b)%b;
		add((c[i]+1),c[i]+(c[i+1]-c[i]+b)%b);
	}
	long long ret=val;
	long long now=0;
	long long dx=0;
	long long ddx=0;
//	for(int i=0;i<2*b;i++)printf("%lld %lld\n",sum[i],sum2[i]);
	for(int i=0;i<2*b;i++){
		now+=dx;
		dx+=sum[i]+ddx;
		ddx+=sum2[i];
		tot[i%b]+=dx;
//		ret=min(ret,val-dx);
	}
	for(int i=0;i<b;i++)ret=min(ret,val-tot[i]);
	printf("%lld\n",ret);
}