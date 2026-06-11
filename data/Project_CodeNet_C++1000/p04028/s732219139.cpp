#include<bits/stdc++.h>
#define gc getchar()
#define ll long long
#define pb push_back
#define mk make_pair
#define rint register int
#define int long long
using namespace std;
const int mod = 1e9+7;
inline int read(){int w=1,s=0;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}return  w*s;}
int N,f[5050][5050];
char s[5050];
inline ll ksm(ll x,ll y){ll res=1; while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;} return res;}
signed main()
{
	N=read();scanf("%s",s+1);
	f[0][0]=1;int len=strlen(s+1);
	for(rint i=0;i<N;++i){
		for(rint j=0;j<=N;++j)
		{
			if(f[i][j])
			{
				(f[i+1][j+1]+=2ll*f[i][j]%mod)%=mod;
				f[i+1][j+1]%=mod;
				(f[i+1][max(j-1,0ll)]+=f[i][j])%=mod;
				f[i+1][max(j-1,0ll)]%=mod;
			}
		}
	}
	cout<<1ll*f[N][len]*ksm(ksm(2,len),mod-2)%mod;
	return 0;
}
/*
by was_n
18.11.15
*/
