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
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
long long Comb(int a,int b){
 	if(a<b||b<0)return 0;
 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
void init_C(int n){
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<n;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<n;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
// ここから編集しろ
int b[110000];
long long ans[110000];
int z[110000];
long long bit[110000][2];
long long sum(int a,int b,int c){
	if(a)return sum(0,b,c)-sum(0,a-1,c);
	long long ret=0;
	for(;b>=0;b=(b&(b+1))-1)ret+=bit[b][c];
	return ret;
}
void add(int a,long long b,int c){
	for(;a<110000;a|=a+1)bit[a][c]+=b;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++)z[i]=b[i];
	std::sort(z,z+a);
	long long S=0;
	for(int i=0;i<a;i++){
		S+=b[i];
		add(lower_bound(z,z+a,b[i])-z,b[i],0);
		add(lower_bound(z,z+a,b[i])-z,1,1);
	}
	int now=0;
	long long las=S;
	for(int i=0;i<a;i++){
		if(now<b[i]){
			now=b[i];
			long long tmp=sum(lower_bound(z,z+a,b[i])-z,a-1,0);
			tmp-=sum(lower_bound(z,z+a,b[i])-z,a-1,1)*b[i];
			long long nx=tmp;
			ans[i]=las-nx;
			las=nx;
		}

		add(lower_bound(z,z+a,b[i])-z,-b[i],0);
		add(lower_bound(z,z+a,b[i])-z,-1,1);
	}
	for(int i=0;i<a;i++){
		printf("%lld\n",ans[i]);
	}
}