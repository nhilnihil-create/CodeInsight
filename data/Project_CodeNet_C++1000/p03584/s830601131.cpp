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
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int p[110000];
int q[110000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d%d",p+i,q+i);
	}
	long long ret=0;
	int cur=0;
	for(int i=29;i>=0;i--){
		if(b&(1<<i)){
			int t=cur+(1<<i)-1;
			long long tmp=0;
			for(int j=0;j<a;j++){
				if((t&p[j])==p[j])tmp+=q[j];
			}
			ret=max(ret,tmp);
			cur+=1<<i;
		}
		if(i==0){
			int t=cur;
			long long tmp=0;
			for(int j=0;j<a;j++){
				if((t&p[j])==p[j])tmp+=q[j];
			}
			ret=max(ret,tmp);
		}
	}
	printf("%lld\n",ret);
}