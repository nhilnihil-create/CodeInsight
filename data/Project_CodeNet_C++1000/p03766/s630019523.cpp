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
const long double EPS = 1e-14;
const long double INF = 1e+20;
const long double PI = acos(-1);
const int mat_N=3;
const int mat_M=3;
// long long, including mod calculation
struct mat{
	long long a[mat_N][mat_M];
	mat(){for(int i=0;i<mat_N;i++)for(int j=0;j<mat_M;j++)a[i][j]=0;}
	mat(int s){for(int i=0;i<mat_N;i++)for(int j=0;j<mat_M;j++)a[i][j]=(i==j)*s;}
	mat operator+(const mat &m)const{
		mat ret;
		for(int i=0;i<mat_N;i++)for(int j=0;j<mat_M;j++)ret.a[i][j]=a[i][j]+m.a[i][j];
		return ret;
	}
	mat operator-(const mat &m)const{
		mat ret;
		for(int i=0;i<mat_N;i++)for(int j=0;j<mat_M;j++)ret.a[i][j]=a[i][j]+m.a[i][j];
		return ret;
	}
	mat operator-()const{
		mat ret;
		for(int i=0;i<mat_N;i++)for(int j=0;j<mat_M;j++)ret.a[i][j]=-a[i][j];
		return ret;
	}
	mat operator*(const long long &k)const{
		mat ret;
		for(int i=0;i<mat_N;i++)for(int j=0;j<mat_M;j++)ret.a[i][j]=a[i][j]*k%mod;
		return ret;
	}
	// assuming mat_N = mat_M
	// by changing here, you can use for graph problems (ex. a[i][j]=min(a[i][k]+a[k][j]))
	mat operator*(const mat &m)const{
		mat ret;
		for(int k=0;k<mat_N;k++)for(int i=0;i<mat_N;i++)for(int j=0;j<mat_N;j++){
			ret.a[i][j]=(ret.a[i][j]+a[i][k]*m.a[k][j])%mod;
		}
		return ret;
	}
};
mat I=mat(1);
mat pw(mat a,long long t){
	mat ret=I;
	while(t){
		if(t&1){
			ret=ret*a;
		}
		t/=2;
		a=a*a;
	}
	return ret;
}
 
long long calc(long long a){
	mat w;
	w.a[0][0]=1;
	w.a[0][1]=mod-1;
	w.a[0][2]=1;
	w.a[1][0]=1;
	w.a[2][0]=1;
	w.a[2][2]=1;
	mat v=pw(w,a);
	long long SM=v.a[2][0];
	long long TP=v.a[0][0];
	long long n=a%mod;
	return (n+1+(n)*(SM+TP+mod-1)%mod+SM*(n)%mod*(n))%mod;
}
int main(){
	long long a;scanf("%lld",&a);
	printf("%lld\n",calc(a-1));
}