#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int p[110];
int q[110];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	if(a==1){
		printf("1 1 1");
		return 0;
	}
	int ki=0;
	for(int i=0;i<b;i++){
		scanf("%d",p+i);
		if(p[i]%2)ki++;
	}
	if(ki>2){
		printf("Impossible\n");return 0;
	}
	if(b==1){
		printf("%d\n",p[0]);printf("2\n%d %d\n",p[0]-1,1);return 0;
	}
	int sz=0;
	for(int i=0;i<b;i++){
		if(p[i]%2){
			q[sz++]=p[i];
		}
	}
	q[b-1]=q[1];
	if(sz>1)sz=1;
	for(int i=0;i<b;i++){
		if(p[i]%2==0){
			q[sz++]=p[i];
		}
	}
	for(int i=0;i<b;i++){
		printf("%d ",q[i]);
	}printf("\n");
	q[0]--;q[b-1]++;
	if(q[0]==0){
		printf("%d\n",b-1);
		for(int i=1;i<b;i++)printf("%d ",q[i]);
		printf("\n");
	}else{
		printf("%d\n",b);
		for(int i=0;i<b;i++)printf("%d ",q[i]);
		printf("\n");
	}
}