#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
vector<long long int> adj[200001];
bool vis[200001];
#define ll long long int
#define ull unsigned long long int
#define MAX 1000000007
#define MOD 998244353

#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST ll t;cin>>t;while(t--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));

ll power(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a;
        b/=2;
        a=a*a;
    }
    return(ans);
}

int main(){
    IO
    ll N,A;
    cin>>N>>A;
    ll x[N+1],sum=0;
    for(ll i=1;i<=N;i++) {cin>>x[i];sum+=x[i];}
    ll tot_choose=sum/N;
    ll dp[N+1][N+1][sum+1];
    for(ll i=0;i<=N;i++){
        for(ll j=0;j<=N;j++){
            for(ll k=0;k<=sum;k++){
                if(i==0 && j==0 && k==0) dp[i][j][k]=1;
                else if(i>=1 && k<x[i]) dp[i][j][k]=dp[i-1][j][k];
                else if(i>=1 && j>=1 && k>=x[i]) dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i]];
                else dp[i][j][k]=0;
            }
        }
    }
    ll ans=0;
    for(ll j=1;j<=N&&j*A<=sum;j++) ans+=dp[N][j][j*A];
    cout<<ans;
    return(0);
}