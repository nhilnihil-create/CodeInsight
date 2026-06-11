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
int p[5100];
int L[5100][5100];
int R[5100][5100];
int sum[5100];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	L[0][0]=R[a][0]=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(L[i][j]){
				L[i+1][j]=1;
				if(j+p[i]<b)L[i+1][j+p[i]]=1;
			}
		}
	}
	for(int i=a;i>=0;i--){
		for(int j=0;j<b;j++){
			if(R[i][j]){
				R[i-1][j]=1;
				if(j+p[i-1]<b)R[i-1][j+p[i-1]]=1;
			}
		}
	}
	int ret=0;
	for(int i=0;i<a;i++){
		if(p[i]>=b)continue;
		for(int j=0;j<=b;j++)sum[j]=0;
		for(int j=0;j<b;j++){
			sum[j+1]=sum[j]+R[i+1][j];
		}
		bool ok=true;
		for(int j=0;j<b;j++){
			if(!L[i][j])continue;
			int left=max(0,b-p[i]-j);
			int right=b-j;
			if(sum[right]!=sum[left]){
				ok=false;break;
			}
		}
		if(ok)ret++;
	}
	printf("%d\n",ret);
}