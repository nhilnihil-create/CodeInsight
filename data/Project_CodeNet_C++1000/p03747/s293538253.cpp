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
int p[110000];
int q[110000];
int r[110000];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	long long pas=0;
	for(int i=0;i<a;i++){
		scanf("%d%d",p+i,q+i);
		if(q[i]==1){
			r[i]=(p[i]+c)%b;
			pas+=(c+p[i])/b;
		}else{
			r[i]=(p[i]-(c%b)+b)%b;
			if(c-p[i]>=0)pas-=(c-p[i]+b-1)/b;
		}
	}
	pas=(pas%a+a)%a;
	std::sort(r,r+a);
	for(int i=0;i<a;i++){
		printf("%d\n",r[(pas+i)%a]);
	}
}