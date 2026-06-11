//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int dp[ar][ar];
vi reb[arr];
int dp1[ar];
int max_deep_from[arr];

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

int sz_down[arr];

int K;

void dfs(int now,int pred)
{
    max_deep_from[now]=1;
    sz_down[now]=1;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
            sz_down[now]+=sz_down[wh];
            max_deep_from[now]=max(max_deep_from[now],max_deep_from[wh]+1);
        }
    }
    fill_n(dp[now],ar,1e9);
    dp[now][1]=0;
    int cur=1;
    for (auto wh:reb[now]){
        if (wh!=pred){
            fill_n(dp1,ar,1e9);
            for (int j=1;j<=cur;j++){
                for (int k=0;k<=max_deep_from[wh];k++){
                    if (j+k<=K){
                        minimize(dp1[max(j,k+1)],
                        dp[now][j]+dp[wh][k]);
                    }
                }
            }
            for (int j=0;j<ar;j++){
                dp[now][j]=dp1[j];
            }
            cur+=max_deep_from[wh];
        }
    }
    dp[now][0]=sz_down[now];
//    for (int i=0;i<=max_deep_from[now];i++){
//        cout<<"dp["<<now<<"]["<<i<<"] :: "<<dp[now][i]<<"\n";
//    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;
    k++;
    K=k;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs(1,1);
    int ans=1e9;
    for (int i=1;i<=n;i++){
        ans=min(ans,*min_element(dp[i]+1,dp[i]+k+1)+n-sz_down[i]);
    }
    cout<<ans<<"\n";
}
