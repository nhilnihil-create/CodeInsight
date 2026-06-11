#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define INF 0X3F3F3F3F
#define N 100005
#define M 2000100
#define LL long long
#define FF(i,a,b) for(int i=a;i<=b;++i)
#define RR(i,a,b) for(int i=a;i>=b;--i)
#define FJ(i,a,b) for(int i=a;i<b;++i)
#define SC(x) scanf("%d",&x)
#define SCC(x,y) scanf("%d%d",&x,&y)
#define SCCC(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SS(x) scanf("%s",x)
#define PR(x) printf("%d\n",x)
#define CL(a,b) memset(a,b,sizeof(a))
#define FD T&q=fd[rt],&ql=fd[rt<<1],&qr=fd[rt<<1|1]
#define MID int mid=((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define zero(x) (((x)>0?(x):-(x))<EPS)
#define PB push_back
#define SZ size
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define MP make_pair
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
using namespace std;
const LL MOD=1000000007;
int n, a[N], f[N];
int p, cnt;
LL ans = 1;
int main(){
 //   IN;
    SC(n);
    FF(i, 1, n)SC(a[i]);
    FF(i, 1, n){
        f[p] = i;
        int t = (a[i] + 1) >> 1;
        if(i > t)p = max(p, i - t);
    }
    RR(i, n, 1)f[i] = f[i - 1];
    f[0] = 0;
    FF(i, 1, n){
        int tmp = max(f[i] - f[i-1], 0);
        cnt += tmp;
        ans = ans * cnt % MOD;
        --cnt;
    }
    printf("%lld\n", ans);
return 0;
}
