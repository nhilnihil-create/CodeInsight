#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define int long long
#define hh puts("")
#define pc putchar
#define mo 1000000007
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
const int N=4000005,M=2005;
int n,k,jc[N],ny[N],f[M][M];
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+(ch^48);ch=getchar();}
    return ret*ff;
}
void write(int x){if(x<0){x=-x,pc('-');}if(x>9) write(x/10);pc(x%10+48);}
void writeln(int x){write(x),hh;}
void writesp(int x){write(x),pc(' ');}
//总共n个白球,n*(k-1)个其他颜色球,时刻满足白球个数大于等于其余颜色个数 
//f[i][j]:放i个白球,用了j种颜色的方案 
int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%mo;
		y>>=1;
		x=x*x%mo;
	}
	return res;
}
int C(int x,int y){
	return jc[x]*ny[y]%mo*ny[x-y]%mo;
}
signed main(){
	n=read(),k=read();
	if(k==1){
		write(1);
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<=N-5;i++) jc[i]=jc[i-1]*i%mo;
	ny[N-5]=ksm(jc[N-5],mo-2);
	for(int i=N-6;i>=0;i--) ny[i]=ny[i+1]*(i+1)%mo;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i][j]=f[i-1][j];
			if(j>0) f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%mo*C(n*k-i-(j-1)*(k-1)-1,k-2)%mo)%mo;
		}
	}
	write(f[n][n]);
    return 0;
}