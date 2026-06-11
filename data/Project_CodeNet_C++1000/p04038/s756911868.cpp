#include<bits/stdc++.h> 
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
typedef long long ll;
using namespace std;
const int maxn=2e3+5,mo=1e9+7;
int i,j,n,k,f[maxn][maxn],ji[maxn*maxn],ni[maxn*maxn];
int qs(int x,int y){
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%mo) if(y&1) s=(ll)s*x%mo;
	return s; 
}
int calc(int n,int  m){
	return (ll)ji[n]*ni[m]%mo*ni[n-m]%mo;
}
void mod(int &x){
	x-=(x>=mo)?mo:0;
}
int main(){
	scanf("%d%d",&n,&k);
	if (k==1){
        printf("1\n");
        return 0;
    }
	ji[0]=1;
	fo(i,1,n*k) ji[i]=(ll)ji[i-1]*i%mo;
	ni[n*k]=qs(ji[n*k],mo-2);
	fd(i,n*k,1) ni[i-1]=(ll)ni[i]*i%mo;
	f[0][0]=1;
	fo(i,0,n){
		fd(j,i,0) if (f[i][j]){
			int s=f[i][j];
			if (j) mod(f[i][j-1]+=s);
			if (i<n) mod(f[i+1][j+1]+=(ll)s*calc(i*k-j+k-2,k-2)%mo);
		}
	}
	printf("%d\n",(ll)f[n][0]*ji[n]%mo);
}