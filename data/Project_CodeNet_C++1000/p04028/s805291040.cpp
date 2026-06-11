#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>=0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const double pi = 3.141592653589793;

int n;
string s;
ll dp[5005][5005];

ll powmod(ll n,ll k,ll mod){
    if (k==0) return 1;
    else if (k%2==0){
        ll tmp=powmod(n,k/2,mod);
        return tmp*tmp%mod;
    }
    else return powmod(n,k-1,mod)*n%mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int ls=s.length();
    dp[0][0]=1;
    rep(i,n)rep(j,n+1){
        if (j-1>=0){
            dp[i+1][j]+=(dp[i][j-1]*2+dp[i][j+1])%mod;
            dp[i+1][j]%=mod;
        }
        else{
            dp[i+1][0]+=(dp[i][0]+dp[i][1])%mod;
            dp[i+1][0]%=mod;
        }
    }
    cout << dp[n][ls]*(powmod(2,ls*(mod-2),mod))%mod << endl;
    return 0;
}