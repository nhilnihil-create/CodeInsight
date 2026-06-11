#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5005;
const int mod=1e9+7;
int n,m;
char s[N];
ll d[N][N];
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    int m=strlen(s);
    if(m>n){
        printf("0\n");
        return 0;
    }
    d[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++){
            if(j!=n)
                d[i][j]+=2*d[i-1][j+1];
            if(j!=0)
                d[i][j]+=d[i-1][j-1];
            else
                d[i][j]+=d[i-1][j];
            d[i][j]%=mod;
        }
    printf("%lld\n",d[n][m]);
}
