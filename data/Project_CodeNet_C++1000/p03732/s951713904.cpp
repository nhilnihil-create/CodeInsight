#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 110;

int n,cnt;
ll W,mi,ans;
int cn[10];
ll val[10][maxn],w[maxn],cw[maxn],wei[10],v[maxn],pre[10][maxn];

bool cmp(ll a,ll b){
	return a>b;
}

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	mi = 1e9 + 7;
	ans = 0;
	n = read(),W = read(); 
	for(int i=1;i<=n;i++){
		w[i] = read(); cw[i] = w[i];
		mi = min(mi, w[i]);
		v[i] = read();
	}
	
	sort(cw+1,cw+1+n);
	
	for(int i = 1;i <= n;i++){
		if(cw[i] != cw[i-1]){
			wei[++cnt] = cw[i];
		}
	}
	
	for(int i=1;i<=n;i++){
		int nt = w[i]-mi+1;
		val[nt][++cn[nt]] = v[i];
	}
	
	for(int i=1;i<=cnt;i++){
		sort(val[i]+1,val[i]+1+cn[i],cmp);
	}
	
	for(int i=1 ;i <= cnt;i++){
		for(int j = 1 ;j<=cn[i]; j++){
			pre[i][j]=val[i][j];
			pre[i][j]+=pre[i][j-1];
		}
	}
	
	if(cnt==4){
		for(int i=0 ;i <= cn[1];i++){
			for( int j= 0;j <= cn[2] ;j++){
				for( int k=0 ;k <= cn[3] ;k++){
					for(int p = 0; p <= cn[4] ; p++){
						if(i*wei[1]+j*wei[2]+k*wei[3]+p*wei[4]<=W){
							ans =max( pre[1][i] + pre[2][j] + pre[3][k] + pre[4][p],ans);
						}
						
					}
				}
			}
		}
	}
		
	if(cnt==3){
		for(int i=0 ;i <= cn[1];i++){
			for( int j= 0;j <= cn[2] ;j++){
				for( int k=0 ;k <= cn[3] ;k++){
					if(i*wei[1]+j*wei[2]+k*wei[3]<=W){
						ans =max( pre[1][i] + pre[2][j] + pre[3][k],ans);
					}
				}
			}
		}
	}
	
		
	if(cnt==2){
		for(int i=0 ;i <= cn[1];i++){
			for( int j= 0;j <= cn[2] ;j++){
				if(i*wei[1]+j*wei[2]<=W){
					ans =max( pre[1][i] + pre[2][j] ,ans);	
				}
			}
		}
	}
	
	if(cnt==1){
		for(int i=0 ;i <= cn[1];i++){
			if(i*wei[1]<=W){
				ans =max( pre[1][i] ,ans);
			}
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
}