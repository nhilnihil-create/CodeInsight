#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=1e6;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n;
long long res,f[N+5],t[N+5];
int main()
{
	//freopen("Infinite Sequence.inp","r",stdin);
	//freopen("Infinite Sequence.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>n;
    f[0]=1; f[1]=1; f[2]=1;
    t[0]=1; t[1]=2; t[2]=3;
    for (int i=3;i<=n;i++)
    {
        f[i]=(t[i-1]-f[i-2]+2*mod)%mod;
        t[i]=(t[i-1]+f[i])%mod;
    }
    for (int i=0;i<=n;i++)
    {
        if (i==n) res=(res + f[i])%mod;
        else if (i==n-1) res=(res+ f[i]*(n-1)%mod)%mod;
        else if (i==n-2) res=(res + f[i]*(n-1)%mod*n%mod)%mod;
        else res=(res+ f[i]*(n-1)%mod*(n-1)%mod +f[i]*(i+1)%mod)%mod;
    }
    cout<<res;
	return 0;
}
