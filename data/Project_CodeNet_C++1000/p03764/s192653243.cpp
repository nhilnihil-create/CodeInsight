#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int Mod = 1000000007;
#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
int x[maxn],y[maxn];
int main() {
    //freopen(".in", "r", stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]);
    ll s1=0,s2=0;
    for(int i=1;i<=n-1;i++) s1=(s1+1LL*i*(n-i)%Mod*(x[i+1]-x[i])%Mod)%Mod;
    for(int i=1;i<=m-1;i++) s2=(s2+1LL*i*(m-i)%Mod*(y[i+1]-y[i])%Mod)%Mod;
    printf("%lld\n",(s1*s2)%Mod);
    return 0;
}

