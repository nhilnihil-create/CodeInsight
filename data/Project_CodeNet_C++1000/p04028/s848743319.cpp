#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ld long double
typedef pair<ll,ll> pii;
const int maxn=5005;
const int mod=1e9+7;
ll f[maxn][maxn];
char s[maxn];
int main()
{
    #ifdef local
    freopen("in.txt","r",stdin);
    #endif // local
    IOS;
    f[0][0]=1;
    for(int i=1;i<=5000;i++)
    {
        for(int j=0;j<=5000;j++)
        {
            f[i][j]+=f[i-1][j+1]*2;
            if(!j) f[i][j]+=f[i-1][j];
            else f[i][j]+=f[i-1][j-1];
            f[i][j]%=mod;
        }
    }
    int n;
    cin>>n;
    cin>>s+1;
    int k=strlen(s+1);
    cout<<f[n][k]<<endl;
}
