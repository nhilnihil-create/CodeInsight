#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

const int mod = 1000000007;

//power_mod
inline int Pow_mod(int x, int pow){
    if(pow==0) return 1;
    int a=Pow_mod(x, pow/2);
    a=a*a%mod;
    if(pow%2==1) a*=x;
    return a%mod;
}

int n;
string s;
int dp[5010][5010];

signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>s;
    dp[0][0]=1;
    rep(i,n){
        rep(j,n+1){
            (dp[i+1][j+1]+=dp[i][j]*2%mod)%mod;
            (dp[i+1][max<int>(0,j-1)]+=dp[i][j])%=mod;
        }
    }

    cout<<dp[n][s.size()]*Pow_mod(Pow_mod(2,s.size()),mod-2)%mod<<endl;
    return 0;

}