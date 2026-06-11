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

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
char s[maxn],t[maxn];
int sum[2][maxn];
int main() {
    //freopen(".in", "r", stdin);
    scanf("%s",s+1);
    scanf("%s",t+1);
    int lens=strlen(s+1);
    int lent=strlen(t+1);
    for(int i=1;i<=lens;i++) sum[0][i]=sum[0][i-1]+(s[i]=='A');
    for(int i=1;i<=lent;i++) sum[1][i]=sum[1][i-1]+(t[i]=='A');
    int q;scanf("%d",&q);
    while(q--)
    {
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        int sum1a = (sum[0][b]-sum[0][a-1]);
        int sum1b = b-a+1-sum1a;
        int sum2a = (sum[1][d]-sum[1][c-1]);
        int sum2b = d-c+1-sum2a;
        int t1 = (sum1a+sum1b*2)%3;
        int t2 = (sum2a+sum2b*2)%3;
        if(t1==t2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

