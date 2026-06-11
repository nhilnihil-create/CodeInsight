#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define met(a, x) memset(a,x,sizeof(a));
#define inf 0x3f3f3f3f
#define mp make_pair;

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 1e5 + 10;
int a[310][310];
bool vis[310];
int f[310], num[310];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        num[i] = 1;
    int flag=0;
    for (int i = 1; i <= m; i++) {
        int maxn=0;
        met(f,0);
        for(int j=1;j<=n;j++){
            f[a[j][num[j]]]++;
            if(f[a[j][num[j]]]>maxn){
                maxn=f[a[j][num[j]]];
                flag=a[j][num[j]];
            }
        }
        vis[flag]=1;
        ans=min(ans,maxn);
        for(int j=1;j<=n;j++){
            while(vis[a[j][num[j]]]==1){
                num[j]++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

