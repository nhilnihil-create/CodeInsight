#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N=5005;
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
void dec(int &a,int b){a-=b;if(a<0)a+=P;}
void add(int &a,int b){a+=b;if(a>=P)a-=P;}
int n,m;
char s[N];
int f[N][N];
int main(){
    scanf("%d",&n);scanf("%s",s+1);
    m=strlen(s+1);
    f[0][0]=1;
    rep(i,0,n-1)rep(j,0,n)if(f[i][j]){
        add(f[i+1][max(0,j-1)],f[i][j]);
        add(f[i+1][j+1],f[i][j]*2%P);
    }
    printf("%d\n",f[n][m]*1ll*Pow(Pow(2,P-2),m)%P);
    return 0;
}


