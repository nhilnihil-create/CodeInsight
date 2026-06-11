#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
int n,len;
char s[5005];
inline void add(int &x,int a)
{
	x+=a;
	if(x>=MOD)x-=MOD;
}
namespace Task1{
	const int MAXN = 305;
	int f[2][MAXN][MAXN];
	inline int solve()
	{
		f[0][0][0]=1;
		for(int i=1;i<=n;++i){
			memset(f[i&1],0,sizeof(f[i&1]));
			for(int j=0;j<=len;++j)
				for(int k=0;k<=i-j;++k){
					int t=f[(i&1)^1][j][k];
					if(!t)continue;
					if(k>0){
						add(f[i&1][j][k+1],t*2%MOD);
						add(f[i&1][j][k-1],t);
					}else{
						if(j<len){
							add(f[i&1][j+1][0],t);
							add(f[i&1][j][1],t);
							add(f[i&1][max(j-1,0)][0],t);
						}else{
							add(f[i&1][j][1],t*2%MOD);
							add(f[i&1][max(j-1,0)][0],t);
						}
					}					
				}
		}
		return f[n&1][len][0];
	}
}
namespace FullMark{
	const int MAXN = 5005;
	int f[2][MAXN];
	inline int solve()
	{
		f[0][0]=1;
		for(int i=1;i<=n;++i){
			memset(f[i&1],0,sizeof(f[i&1]));
			for(int j=0;j<=i;++j){
				int t=f[(i&1)^1][j];
				add(f[i&1][j+1],t*2%MOD);
				add(f[i&1][max(j-1,0)],t);
			}
		}
		int ret=f[n&1][len];
		for(int i=1;i<=len;++i)
			ret=(long long)ret*500000004%MOD;
		return ret;
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	len=strlen(s+1);
	if(n<=300)cout<<Task1::solve()<<endl;
	else cout<<FullMark::solve()<<endl;
	return 0;
}
