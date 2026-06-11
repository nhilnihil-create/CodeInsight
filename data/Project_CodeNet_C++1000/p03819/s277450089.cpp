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
int p[310000];
int q[310000];
vector<int>v[310000];
int bit[110000];
int sum(int a,int b){
	if(a)return sum(0,b)-sum(0,a-1);
	int ret=0;
	for(;b>=0;b=(b&(b+1))-1)ret+=bit[b];
	return ret;
}
void add(int a,int b){
	for(;a<110000;a|=a+1)bit[a]+=b;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d%d",p+i,q+i);
		int len=q[i]-p[i]+1;
		v[len].push_back(i);
	}
	int rem=a;
	for(int i=1;i<=b;i++){
		rem-=v[i].size();
		for(int j=0;j<v[i].size();j++){
			add(p[v[i][j]],1);
			add(q[v[i][j]]+1,-1);
		}
		int ret=rem;
		for(int j=0;j<=b;j+=i){
			ret+=sum(0,j);
		}
		printf("%d\n",ret);
	}
}