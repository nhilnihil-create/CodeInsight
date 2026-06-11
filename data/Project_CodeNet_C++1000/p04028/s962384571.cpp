#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define ll long long
#define N 5005
#define mod 1000000007
#define inv2 500000004
using namespace std;
int n,m,f[2][N]; char s[N];
void upd(int &x,int y){ x+=y; if (x>=mod) x-=mod; }
int main(){
	scanf("%d%s",&m,s+1); n=strlen(s+1);
	//f[i][j]表示第i步，此时有j个数字的方案数
	int nk=0,k=1; f[0][0]=1;
	rep (i,0,m-1){
		nk^=1; k^=1; memset(f[nk],0,sizeof(f[nk]));
		rep (j,0,m){
			upd(f[nk][max(0,j-1)],f[k][j]);
			if (j<m) upd(f[nk][j+1],2ll*f[k][j]%mod);
		}
	}
	int ans=f[nk][n];
	rep (i,1,n) ans=(ll)ans*inv2%mod;
	printf("%d\n",ans);
	return 0;
}